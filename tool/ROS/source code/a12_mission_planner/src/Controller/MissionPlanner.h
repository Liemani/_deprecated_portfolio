#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H

#include <string>
#include <vector>

#include <ros/ros.h>

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateFlyingStateChanged.h>

#include "../Model/GlobalPosition.h"

using std::vector;

class MissionPlanner {
private:
    std::string name;

    ros::NodeHandle* nh;

    uint8_t state;

    int missionState;

    ros::Publisher takeoff_pub;
    ros::Publisher land_pub;
    ros::Publisher reset_pub;
    ros::Publisher cmd_vel_pub;

    ros::Subscriber positionSub;
    ros::Subscriber altitudeSub;
    ros::Subscriber attitudeSub;
    ros::Subscriber flyingStateSub;

    int input_data;
    std_msgs::Empty emptyMsg;
    geometry_msgs::Twist twistMsg;

    GlobalPosition currentPosition;
    GlobalPosition savedPosition;
    
    float roll;
    float pitch;
    float bearing_rad;

    uint8_t flyingState;
    
    // mission variable
    double latitudeA_rad;
    double longitudeA_rad;

    double latitudeB_rad;
    double longitudeB_rad;

    double deltaLatitude_rad;
    double deltaLongitude_rad;



    double a;
    double distance;



    double X;
    double Y;

    double directionAngle;

public:
    MissionPlanner(int argc, char** argv, std::string name = "bebop");

    void moveToTargetPosition();

    void publish();

    void positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg);
    void altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg);
    void attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg);
    void flyingStateChanged(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::ConstPtr& msg);

    void debugDescription();
};

#endif