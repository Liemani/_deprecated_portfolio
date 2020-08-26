#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>

#include <iostream>

void pose_callback(const geometry_msgs::PoseStamped::ConstPtr& msg) {
    std::cout << "Position x: " << msg->pose.position.x << std::endl;
    std::cout << "Position y: " << msg->pose.position.y << std::endl;
    std::cout << "Position z: " << msg->pose.position.z << std::endl;

    std::cout << "Orientation x: " << msg->pose.orientation.x << std::endl;
    std::cout << "Orientation y: " << msg->pose.orientation.y << std::endl;
    std::cout << "Orientation z: " << msg->pose.orientation.z << std::endl;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "get_aruco_pose");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/aruco_single/pose", 1000, pose_callback);

    ros::spin();

    return 0;
}