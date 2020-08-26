#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

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
    ros::Publisher move_pub = nh.advertise<geometry_msgs::Twist>("/bebop/cmd_vel", 1);

    int input_data;
    bool isTakeOff = false;
    std_msgs::Empty msg;

    while (ros::ok()) {
        input_data = getch();

        if (input_data == 32) {
            if (isTakeOff) {
                land_pub.publish(msg);
                isTakeOff = false;
            } else {
                takeoff_pub.publish(msg);
                isTakeOff = true;
            }
        } else if (input_data == 119) {    // forward
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0.5;
            move_msg.linear.y = 0;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;
            
            move_pub.publish(move_msg);
        } else if (input_data == 120) {    // backward
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = -0.5;
            move_msg.linear.y = 0;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;
            
            move_pub.publish(move_msg);
        } else if (input_data == 115 || input_data == 106) {    // hovering
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0;
            move_msg.linear.y = 0;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;
            
            move_pub.publish(move_msg);
        } else if (input_data == 97) {    // left
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0;
            move_msg.linear.y = 0.5;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;
            
            move_pub.publish(move_msg);
        } else if (input_data == 100) {    // right
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0;
            move_msg.linear.y = -0.5;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;
            
            move_pub.publish(move_msg);
        } else if (input_data == 117) {    // up
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0;
            move_msg.linear.y = 0;
            move_msg.linear.z = 0.5;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;
            
            move_pub.publish(move_msg);
        } else if (input_data == 109) {    // down
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0;
            move_msg.linear.y = 0;
            move_msg.linear.z = -0.5;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0;
            
            move_pub.publish(move_msg);
        } else if (input_data == 104) {    // turn left
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0;
            move_msg.linear.y = 0;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = 0.3;
            
            move_pub.publish(move_msg);
        } else if (input_data == 107) {    // turn right
            geometry_msgs::Twist move_msg;

            move_msg.linear.x = 0;
            move_msg.linear.y = 0;
            move_msg.linear.z = 0;

            move_msg.angular.x = 0;
            move_msg.angular.y = 0;
            move_msg.angular.z = -0.3;
            
            move_pub.publish(move_msg);
        }

        ros::spinOnce();
    }

    return 0;
}