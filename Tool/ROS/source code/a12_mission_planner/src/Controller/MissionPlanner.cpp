#include <stdio.h>    // getchar()

#include <string>

#include <termio.h>    // struct termios

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h>

#include "MissionPlanner.h"
#include "../Model/GlobalPosition.h"

#define QUEUE_SIZE 1
#define RATIO 0.5

#define state_landed 0
#define state_takingOff 1
#define state_hovering 2
#define state_flying 3
#define state_landing 4
#define state_emergency 5
#define state_userTakeOff 6
#define state_motorRamping 7
#define state_emergencyLanding 8

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
}

void MissionPlanner::moveToTargetPosition(GlobalPosition targetPosition) {
//     if (rightHeading()) {
//         turn();
//     } else if (haveDistance()) {
//         moveForwardOrBackward();
//     } else {
//         state = stop;
//     }
}

void MissionPlanner::publish() {
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
    yaw = msg->yaw;
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
    printf("Yaw: %.15f \n", yaw);
    printf("\n");
    printf("Flying state: %d \n", flyingState);
    printf("---------------- \n");
}
