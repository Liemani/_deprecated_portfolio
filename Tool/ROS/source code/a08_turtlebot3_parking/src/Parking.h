#ifndef PARKING_H
#define PARKING_H

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Twist.h>
#include <math.h>

class Parking {
private:
    ros::Publisher cmd_pub;
    ros::Subscriber marker_sub;

    int argc;
    char** argv;

    visualization_msgs::Marker marker;
    geometry_msgs::Twist twist;

    int target_marker;

public:
    Parking(int argc, char** argv, int target_marker);
    void poseCallback(const visualization_msgs::Marker::ConstPtr& msg);
    void get_tag();
    void move_to_target_angle();
    void move_to_target_distance();
    void turn_ninety_degree();
    void close_to_marker();

    bool is_find_tag;
    bool is_move_to_target_angle;
    bool is_move_to_target_distance;
    bool is_turn_ninety_degree;
    bool is_close_to_marker;
};




#endif