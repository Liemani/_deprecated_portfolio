#include <stdio.h>    // getchar()

#include <string>    // string
#include <math.h>

#include <termio.h>    // struct termios

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h>

#include "MissionPlanner.h"
#include "../Model/GlobalPosition.h"

#define PI 3.141592
#define RADIUS_OF_EARTH 6371

#define QUEUE_SIZE 1
#define RATIO 0.5
#define SLOW_RATIO 0.05

#define state_landed 0
#define state_takingOff 1
#define state_hovering 2
#define state_flying 3
#define state_landing 4
#define state_emergency 5
#define state_userTakeOff 6
#define state_motorRamping 7
#define state_emergencyLanding 8

#define state_noMission 0
#define state_onMission 1

using std::string;

int getch() {
    int ch;

    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);

    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();

    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}

MissionPlanner::MissionPlanner(int argc, char** argv, string name) {
    ros::init(argc, argv, "a12_mission_planner_node");    // node name
    this->name = name;
    nh = new ros::NodeHandle();

    string prefix = '/' + name;

    positionSub = nh->subscribe(prefix + "/states/ardrone3/PilotingState/PositionChanged", QUEUE_SIZE, &MissionPlanner::positionChanged, this);
    altitudeSub = nh->subscribe(prefix + "/states/ardrone3/PilotingState/AltitudeChanged", QUEUE_SIZE, &MissionPlanner::altitudeChanged, this);
    attitudeSub = nh->subscribe(prefix + "/states/ardrone3/PilotingState/AttitudeChanged", QUEUE_SIZE, &MissionPlanner::attitudeChanged, this);
    flyingStateSub = nh->subscribe(prefix + "/states/ardrone3/PilotingState/FlyingStateChanged", QUEUE_SIZE, &MissionPlanner::flyingStateChanged, this);

    takeoff_pub = nh->advertise<std_msgs::Empty>(prefix + "/takeoff", QUEUE_SIZE);
    land_pub = nh->advertise<std_msgs::Empty>(prefix + "/land", QUEUE_SIZE);
    reset_pub = nh->advertise<std_msgs::Empty>(prefix + "/reset", QUEUE_SIZE);
    cmd_vel_pub = nh->advertise<geometry_msgs::Twist>(prefix + "/cmd_vel", QUEUE_SIZE);

    missionState = state_noMission;
}

void MissionPlanner::moveToTargetPosition() {
    latitudeA_rad = currentPosition.latitude / 180 * PI;
    longitudeA_rad = currentPosition.longitude / 180 * PI;

    latitudeB_rad = savedPosition.latitude / 180 * PI;
    longitudeB_rad = savedPosition.longitude / 180 * PI;

    deltaLatitude_rad = latitudeB_rad - latitudeA_rad;
    deltaLongitude_rad = longitudeB_rad - longitudeA_rad;



    a = pow(sin(deltaLatitude_rad / 2), 2) + cos(latitudeA_rad) * cos(latitudeB_rad) * pow(sin(deltaLongitude_rad / 2), 2);
    distance = RADIUS_OF_EARTH * (2 * atan2(sqrt(a), sqrt(1 - a))) * 1000;



    X = cos(latitudeB_rad) * sin(deltaLongitude_rad);
    Y = cos(latitudeA_rad) * sin(latitudeB_rad) - sin(latitudeA_rad) * cos(latitudeB_rad) * cos(deltaLongitude_rad);

    directionAngle = this->bearing_rad - atan2(X, Y);



    if (distance > 5) {
        twistMsg.linear.x = RATIO * cos(directionAngle);
        twistMsg.linear.y = RATIO * sin(directionAngle);
        twistMsg.linear.z = (savedPosition.altitude - currentPosition.altitude) / distance * RATIO;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else if (distance > 0.05) {
        twistMsg.linear.x = SLOW_RATIO * cos(directionAngle);
        twistMsg.linear.y = SLOW_RATIO * sin(directionAngle);
        twistMsg.linear.z = (savedPosition.altitude - currentPosition.altitude) / distance * SLOW_RATIO;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else {
        missionState = state_noMission;
    }
}

void MissionPlanner::publish() {
    if (missionState == state_noMission) {
        input_data = getch();

        if (input_data == 116 && flyingState == state_landed) {    // takeoff
            takeoff_pub.publish(emptyMsg);
        } else if (input_data == 98 && flyingState == state_hovering) {    // land
            land_pub.publish(emptyMsg);
        } else if (input_data == 103) {    // reset
            reset_pub.publish(emptyMsg);
        } else if (input_data == 119) {    // forward
            twistMsg.linear.x = RATIO;
            twistMsg.linear.y = 0;
            twistMsg.linear.z = 0;
            twistMsg.angular.z = 0;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 115) {    // backward
            twistMsg.linear.x = -RATIO;
            twistMsg.linear.y = 0;
            twistMsg.linear.z = 0;
            twistMsg.angular.z = 0;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 97) {    // leftward
            twistMsg.linear.x = 0;
            twistMsg.linear.y = RATIO;
            twistMsg.linear.z = 0;
            twistMsg.angular.z = 0;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 100) {    // rightward
            twistMsg.linear.x = 0;
            twistMsg.linear.y = -RATIO;
            twistMsg.linear.z = 0;
            twistMsg.angular.z = 0;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 105) {    // upward
            twistMsg.linear.x = 0;
            twistMsg.linear.y = 0;
            twistMsg.linear.z = RATIO;
            twistMsg.angular.z = 0;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 107) {    // downward
            twistMsg.linear.x = 0;
            twistMsg.linear.y = 0;
            twistMsg.linear.z = -RATIO;
            twistMsg.angular.z = 0;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 106) {    // turn left
            twistMsg.linear.x = 0;
            twistMsg.linear.y = 0;
            twistMsg.linear.z = 0;
            twistMsg.angular.z = RATIO;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 108) {    // turn right
            twistMsg.linear.x = 0;
            twistMsg.linear.y = 0;
            twistMsg.linear.z = 0;
            twistMsg.angular.z = -RATIO;

            cmd_vel_pub.publish(twistMsg);
        }  else if (input_data == 113) {    // hovering
            twistMsg.linear.x = 0;
            twistMsg.linear.y = 0;
            twistMsg.linear.z = 0;
            twistMsg.angular.z = 0;

            cmd_vel_pub.publish(twistMsg);
        } else if (input_data == 122) {    // save current position to savedPosition
            savedPosition.latitude = currentPosition.latitude;
            savedPosition.longitude = currentPosition.longitude;
            savedPosition.altitude = currentPosition.altitude;
        } else if (input_data == 120) {    // move to savedPosition
            missionState = state_onMission;
        }
    } else if (missionState == state_onMission) {
        moveToTargetPosition();
    }
}

void MissionPlanner::positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg) {
    currentPosition.latitude = msg->latitude;
    currentPosition.longitude = msg->longitude;
}

void MissionPlanner::altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg) {
    currentPosition.altitude = msg->altitude;
}

void MissionPlanner::attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg) {
    roll = msg->roll;
    pitch = msg->pitch;
    bearing_rad = msg->yaw;    // msg->yaw is magnetic bearing_rad
}

void MissionPlanner::flyingStateChanged(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::ConstPtr& msg) {
    flyingState = msg->state;
}

void MissionPlanner::debugDescription() {
    ROS_INFO(" ");    // for to stamp time
    // printf("state: %f \n", this->state);
    printf("\n");
    printf("Latitude: %.15f \n", currentPosition.latitude);
    printf("Longitude: %.15f \n", currentPosition.longitude);
    printf("Altitude: %.15f \n", currentPosition.altitude);
    printf("\n");
    printf("Roll: %.15f \n", roll);
    printf("Pitch: %.15f \n", pitch);
    printf("Yaw: %.15f \n", bearing_rad);
    printf("\n");
    printf("Flying state: %d \n", flyingState);
    printf("---------------- \n");
}
