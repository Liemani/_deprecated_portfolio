#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Twist.h>

#define MAX_SPEED 0.05
#define DEADZONE 0.0025

 ros::Publisher cmd_vel;
 ros::Subscriber ar_pose;

void clamp(double& speed, double min, double max) {
    if (speed > max) {
        speed = max;
    } else if (speed < min) {
        speed = min;
    }
}

void dead(double& toDead, double deadZone) {
    if (-deadZone < toDead && toDead < deadZone) {
        toDead = 0.0;
    }
}

void poseCallback(const visualization_msgs::Marker::ConstPtr& msg) {
    double position_x = msg->pose.position.x;
    double position_y = msg->pose.position.y;
    double position_z = msg->pose.position.z;
    double orientation_z = msg->pose.orientation.z;

    double forward = position_z;
    double turn = -(position_x + orientation_z);

    forward = forward > 0 ? pow(fabs(forward), 1.57) : -pow(fabs(forward), 1.57);
    turn = turn > 0 ? pow(fabs(turn), 1.57) : -pow(fabs(turn), 1.57);

    clamp(forward, -MAX_SPEED, MAX_SPEED);
    clamp(turn, -MAX_SPEED, MAX_SPEED);

    dead(forward, DEADZONE);
    dead(turn, DEADZONE);

    geometry_msgs::Twist move;

    move.linear.x = -forward;
    move.linear.y = 0;
    move.linear.z = 0;
    move.angular.x = 0;
    move.angular.y = 0;
    move.angular.z = turn;

    cmd_vel.publish(move);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "a07_turtlebot3_ar_tracker");
    ros::NodeHandle nh;

    cmd_vel = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1);
    ar_pose = nh.subscribe("/aruco_multi/marker", 1, poseCallback);

    try {
        ros::spin();
    } catch(...) {
        ROS_ERROR("ERROR!!!!!");
        ros::shutdown();
    }

    return 0;
}