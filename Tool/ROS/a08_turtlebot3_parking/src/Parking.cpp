#include "Parking.h"

Parking::Parking(int argc, char** argv, int target_marker) {
    this->argc = argc;
    this->argv = argv;
    this->target_marker = target_marker;

    ros::init(this->argc, this->argv, "a08_turtlebot3_parking_node");    // really? was that node's name?
    ros::NodeHandle nh;

    this->marker_sub = nh.subscribe("/aruco_multi/marker", 1, &Parking::poseCallback, this);
    this->cmd_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
}

void Parking::poseCallback(const visualization_msgs::Marker::ConstPtr& msg) {
    this->marker.id = msg->id;
    this->marker.pose = msg->pose;
}

void Parking::get_tag() {
    if (this->marker.id == target_marker) {
        ROS_INFO("Found Marker: %d", this->marker.id);

        this->twist.linear.x = 0;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = 0;

        this->cmd_pub.publish(this->twist);

        ROS_INFO("is_find_tag: %d", is_find_tag);
        this->is_find_tag = true;
        ROS_INFO("is_find_tag: %d", is_find_tag);
    } else {
        ROS_INFO("Finding...");

        this->twist.linear.x = 0;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = 0.2;

        this->cmd_pub.publish(this->twist);
    }
}

void Parking::move_to_target_angle() {
    double target_angle = atan2(this->marker.pose.position.y, this->marker.pose.position.x) - (90 * 3.14 / 180);

    int wise = 1;

    if (marker.pose.orientation.z < 0) {
        wise = 1;
    } else {
        wise = -1;
    }

    // if bigger than 0.05rad/s, rotate 2s or 1s

    if (target_angle > 0.05 || target_angle < -0.05) {
        this->twist.linear.x = 0;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = target_angle * wise / 2;

        this->cmd_pub.publish(this->twist);
        
        ros::Duration(2).sleep();
    } else {
        this->twist.linear.x = 0;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = target_angle * wise;

        this->cmd_pub.publish(this->twist);
        
        ros::Duration(1).sleep();
    }

    is_move_to_target_angle = true;
}

void Parking::move_to_target_distance() {
    double target_distance = sqrt(pow(this->marker.pose.position.x, 2) + pow(this->marker.pose.position.z, 2));
    double target_linear = target_distance * cos(atan2(this->marker.pose.position.y, this->marker.pose.position.x) - (90 * 3.14 / 180));

    if (target_linear < 0.05 || target_linear > -0.05) {
        this->twist.linear.x = target_linear;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = 0;

        this->cmd_pub.publish(twist);
        ros::Duration(1).sleep();
    } else {
        this->twist.linear.x = target_linear / 2;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = 0;

        this->cmd_pub.publish(twist);
        ros::Duration(2).sleep();
    }

    is_move_to_target_distance = true;
}

void Parking::turn_ninety_degree() {
    int wise = 1;

    if (marker.pose.orientation.z < 0) {
        wise = 1;
    } else {
        wise = -1;
    }

    this->twist.linear.x = 0;
    this->twist.linear.y = 0;
    this->twist.linear.z = 0;

    this->twist.angular.x = 0;
    this->twist.angular.y = 0;
    this->twist.angular.z = 1.57 * wise;

    this->cmd_pub.publish(twist);
    ros::Duration(1).sleep();

    is_turn_ninety_degree = true;
}

void Parking::close_to_marker() {
    double target_linear = this->marker.pose.position.z;

    if (target_linear > 0.05) {
        this->twist.linear.x = target_linear / 2;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = 0;

        this->cmd_pub.publish(twist);
        ros::Duration(2).sleep();
    } else {
        this->twist.linear.x = target_linear;
        this->twist.linear.y = 0;
        this->twist.linear.z = 0;

        this->twist.angular.x = 0;
        this->twist.angular.y = 0;
        this->twist.angular.z = 0;

        this->cmd_pub.publish(twist);
        ros::Duration(1).sleep();
    }

    this->twist.linear.x = 0;
    this->twist.linear.y = 0;
    this->twist.linear.z = 0;

    this->twist.angular.x = 0;
    this->twist.angular.y = 0;
    this->twist.angular.z = 0;

    this->cmd_pub.publish(twist);

    is_close_to_marker = true;
}