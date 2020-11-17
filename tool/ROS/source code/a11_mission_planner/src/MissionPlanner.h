#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H

#include <ros/ros.h>

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

class MissionPlanner {
private:
    ros::NodeHandle* nh;

    ros::Publisher takeoff_pub;
    ros::Publisher land_pub;
    ros::Publisher reset_pub;
    ros::Publisher cmd_vel_pub;

    int input_data;
    std_msgs::Empty emptyMsg;
    geometry_msgs::Twist twistMsg;

public:
    MissionPlanner(int argc, char** argv);
    void publish();

};

#endif