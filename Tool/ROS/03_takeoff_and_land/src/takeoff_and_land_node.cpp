#include <ros/ros.h>
#include <std_msgs/Empty.h>

#include <stdio.h>
#include <termio.h>

#include <iostream>

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

int main(int argc, char** argv) {
    ros::init(argc, argv, "takeoff_and_land");
    ros::NodeHandle nh;

    ros::Publisher takeoff_pub = nh.advertise<std_msgs::Empty>("/bebop/takeoff", 1);
    ros::Publisher land_pub = nh.advertise<std_msgs::Empty>("/bebop/land", 1);

    int input_data;
        std_msgs::Empty msg;
    while (ros::ok()) {
        input_data = getch();

        if (input_data == 49) {
            takeoff_pub.publish(msg);
        } else if (input_data == 50) {
            land_pub.publish(msg);
        }

        ros::spinOnce();
    }

    return 0;
}