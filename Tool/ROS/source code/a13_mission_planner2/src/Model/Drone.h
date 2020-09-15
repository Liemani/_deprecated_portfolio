#ifndef DRONE_H
#define DRONE_H

#include <ros/ros.h>
#include <string>

#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h>
#include <nav_msgs/Odometry.h>

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include "CartesianCoordinate.h"

#include "GlobalPosition.h"





class Drone {
private:
    std::string name;

    std_msgs::Empty emptyMsg;
    geometry_msgs::Twist twistMsg;

    ros::Subscriber positionSub;
    ros::Subscriber altitudeSub;
    ros::Subscriber attitudeSub;
    ros::Subscriber flyingStateSub;
    ros::Subscriber odometrySub;

    ros::Publisher takeoff_pub;
    ros::Publisher land_pub;
    ros::Publisher reset_pub;
    ros::Publisher cmd_vel_pub;

    // subscribe variable
    uint8_t flyingState;

    GlobalPosition currentGlobalPosition;
    CartesianCoordinate currentCalculatedPosition;
    
    float bearing;

    void positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg);
    void altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg);
    void attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg);
    void flyingStateChanged(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::ConstPtr& msg);
    void odometryChanged(const nav_msgs::Odometry::ConstPtr& msg);

public:
    Drone(string name, ros::NodeHandle* nodeHandle);

    void takeoff();
    void land();
    void reset();
    void fly(double x, double y, double z, double yaw);
    
};

#endif