#include <stdio.h>    // getchar()
#include <termio.h>    // struct termios

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include "MissionPlanner.h"

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
    ros::init(argc, argv, "mission_planner");
    nh = new ros::NodeHandle();

    takeoff_pub = nh->advertise<std_msgs::Empty>("/bebop/takeoff", 1);
    land_pub = nh->advertise<std_msgs::Empty>("/bebop/land", 1);
    reset_pub = nh->advertise<std_msgs::Empty>("/bebop/reset", 1);
    cmd_vel_pub = nh->advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);
}

void MissionPlanner::publish() {
    input_data = getch();

    if (input_data == 116) {    // takeoff
        takeoff_pub.publish(emptyMsg);
        return;
    } else if (input_data == 98) {    // land
        land_pub.publish(emptyMsg);
        return;
    } else if (input_data == 103) {    // reset
        reset_pub.publish(emptyMsg);
        return;
    } else if (input_data == 119) {    // forward
        twistMsg.linear.x = 0.5;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 115) {    // backward
        twistMsg.linear.x = -0.5;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 97) {    // leftward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0.5;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 100) {    // rightward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = -0.5;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0;
    } else if (input_data == 105) {    // upward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0.5;
        twistMsg.angular.z = 0;
    } else if (input_data == 107) {    // downward
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = -0.5;
        twistMsg.angular.z = 0;
    } else if (input_data == 106) {    // turn left
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = 0.5;
    } else if (input_data == 108) {    // turn right
        twistMsg.linear.x = 0;
        twistMsg.linear.y = 0;
        twistMsg.linear.z = 0;
        twistMsg.angular.z = -0.5;
    } 

    cmd_vel_pub.publish(twistMsg);
}