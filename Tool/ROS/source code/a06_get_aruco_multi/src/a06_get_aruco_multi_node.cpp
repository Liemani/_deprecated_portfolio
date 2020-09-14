#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

void printMsg(const visualization_msgs::Marker::ConstPtr& msg) {
    ROS_INFO("---");
    ROS_INFO("id: %d", msg->id);
    ROS_INFO("pose:");
    ROS_INFO("  position:");
    ROS_INFO("    x: %f", msg->pose.position.x);
    ROS_INFO("    y: %f", msg->pose.position.y);
    ROS_INFO("    z: %f", msg->pose.position.z);
    ROS_INFO("  orientation:");
    ROS_INFO("    x: %f", msg->pose.orientation.x);
    ROS_INFO("    y: %f", msg->pose.orientation.y);
    ROS_INFO("    z: %f", msg->pose.orientation.z);
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "a06_get_aruco_multi");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/aruco_multi/marker", 1000, printMsg);

    ros::spin();

    return 0;
}