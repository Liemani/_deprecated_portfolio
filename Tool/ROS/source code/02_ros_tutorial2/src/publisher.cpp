#include <ros/ros.h>
#include <std_msgs/String.h>

#include <sstream>

int main(int argc, char** argv) {
    ros::init(argc, argv, "publisher_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::String>("hello_ros", 1000);    // publish topic

    ros::Rate loop_rate(10);

    int cnt = 0;

    while(ros::ok()) {
        std_msgs::String msg;
        std::stringstream ss;

        ss << "Hello Ros: " << cnt;

        msg.data = ss.str();

        ROS_INFO("%s", msg.data.c_str());

        pub.publish(msg);
        ros::spinOnce();

        loop_rate.sleep();
        ++cnt;
    }

    return 0;
}