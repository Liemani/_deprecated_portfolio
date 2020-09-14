#include <stdio.h>    // getchar()

#include <termio.h>    // struct termios

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include "MissionPlanner.h"
#include "../Model/GlobalPosition.h"
#include "../Model/MissionPlannerState.h"

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

MissionPlanner::MissionPlanner(int argc, char** argv) {
    ros::init(argc, argv, "a12_mission_planner");    // project name
    nh = new ros::NodeHandle();

    state = stop;

    positionSub = nh->subscribe("/bebop/states/ardrone3/PilotingState/PositionChanged", 1, &MissionPlanner::positionChanged, this);
    altitudeSub = nh->subscribe("/bebop/states/ardrone3/PilotingState/AltitudeChanged", 1, &MissionPlanner::altitudeChanged, this);
    attitudeSub = nh->subscribe("/bebop/states/ardrone3/PilotingState/AttitudeChanged", 1, &MissionPlanner::attitudeChanged, this);

    takeoff_pub = nh->advertise<std_msgs::Empty>("/bebop/takeoff", 1);
    land_pub = nh->advertise<std_msgs::Empty>("/bebop/land", 1);
    reset_pub = nh->advertise<std_msgs::Empty>("/bebop/reset", 1);
    cmd_vel_pub = nh->advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);
}

MissionPlannerState MissionPlanner::getState() {
    return state;
}

void MissionPlanner::moveToTargetPosition() {
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

    if (input_data == 116) {    // takeoff
        takeoff_pub.publish(emptyMsg);
    } else if (input_data == 98) {    // land
        land_pub.publish(emptyMsg);
    } else if (input_data == 103) {    // reset
        reset_pub.publish(emptyMsg);
    } else if (input_data == 119) {    // forward
        twistMsg.linear.x = 0.5;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else if (input_data == 115) {    // backward
        twistMsg.linear.x = -0.5;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else if (input_data == 97) {    // leftward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0.5;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else if (input_data == 100) {    // rightward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = -0.5;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else if (input_data == 105) {    // upward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0.5;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else if (input_data == 107) {    // downward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = -0.5;
        twistMsg.angular.z = 0;

        cmd_vel_pub.publish(twistMsg);
    } else if (input_data == 106) {    // turn left
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0.5;

        cmd_vel_pub.publish(twistMsg);
    } else if (input_data == 108) {    // turn right
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = -0.5;

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

void MissionPlanner::debugDescription() {
    ROS_INFO(" ");    // for to stamp time
    // printf("state: %f \n", this->state);
    printf("\n");
    printf("latitude: %.15f \n", currentPosition.latitude);
    printf("longitude: %.15f \n", currentPosition.longitude);
    printf("altitude: %.15f \n", currentPosition.altitude);
    printf("\n");
    printf("roll: %.15f \n", roll);
    printf("pitch: %.15f \n", pitch);
    printf("yaw: %.15f \n", yaw);
    printf("---------------- \n");
}
