#include <ros/ros.h>
#include <std_msgs/String.h>

void string_callback(const std_msgs::String::ConstPtr& msg) {
    ROS_INFO("I heard '%s'", msg->data.c_str());
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "subscriber_node");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/hello_ros", 1000, string_callback);

    ros::spin();

    return 0;
}