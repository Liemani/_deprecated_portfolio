#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H

#include <vector>

#include <ros/ros.h>

#include <std_msgs/Empty.h>
#include <geometry_msgs/Twist.h>

#include <bebop_msgs/Ardrone3PilotingStatePositionChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAltitudeChanged.h>
#include <bebop_msgs/Ardrone3PilotingStateAttitudeChanged.h>

#include "GlobalPosition.h"
#include "MissionPlannerState.h"

using std::vector;

class MissionPlanner {
private:
    ros::NodeHandle* nh;

    MissionPlannerState state;

    ros::Publisher takeoff_pub;
    ros::Publisher land_pub;
    ros::Publisher reset_pub;
    ros::Publisher cmd_vel_pub;

    ros::Subscriber positionSub;
    ros::Subscriber altitudeSub;
    ros::Subscriber attitudeSub;

    int input_data;
    std_msgs::Empty emptyMsg;
    geometry_msgs::Twist twistMsg;

    GlobalPosition currentPosition;
    
    float roll;
    float pitch;
    float yaw;

public:
    vector<GlobalPosition> targetPositionVector;

    MissionPlanner(int argc, char** argv);

    MissionPlannerState getState();

    void moveToTargetPosition();

    void publish();

    void positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg);
    void altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg);
    void attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg);

    void debugDescription();
};

#endif