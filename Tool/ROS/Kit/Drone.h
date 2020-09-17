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
#include "Mission.h"





class Mission;
class Drone;

typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class Drone {
private:
    std::string name;

    Mission* pMission;

    CallWhenDroneChanged callWhenPositionChanged;
    CallWhenDroneChanged callWhenAltitudeChanged;
    CallWhenDroneChanged callWhenBearingChanged;

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

    GlobalPosition globalPosition;
    CartesianCoordinate calculatedCartesianCoordinateMatchingGlobalPosition;

    CartesianCoordinate calculatedCartesianCoordinate;
    
    float bearing;

    // call back function
    void positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg);
    void altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg);
    void attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg);
    void flyingStateChanged(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::ConstPtr& msg);
    void odometryChanged(const nav_msgs::Odometry::ConstPtr& msg);

public:
    Drone(ros::NodeHandle* pNodeHandle, std::string name = "bebop");

    void debugDescription();

    // get set function
    uint8_t getFlyingState();
    std::string getName();
    float getBearing();

    GlobalPosition getGlobalPosition();

    double getLatitude();
    double getLongitude();
    double getAltitude();

    double getMatchingX();
    double getMatchingY();
    double getMatchingZ();

    double getCalculatedX();
    double getCalculatedY();
    double getCalculatedZ();

    void setMission(Mission* pMission);




    // control function
    void takeoff();
    void land();
    void reset();
    
    void fly(double x, double y, double z, double yaw = 0.0);



    // inline
    void hover() { fly(0, 0, 0, 0); }

    void flyForward(double ratio)   { fly(+ratio, 0, 0, 0); }
    void flyBackward(double ratio)  { fly(-ratio, 0, 0, 0); }
    void flyLeftward(double ratio)  { fly(0, +ratio, 0, 0); }
    void flyRightward(double ratio) { fly(0, -ratio, 0, 0); }
    void flyUpward(double ratio)    { fly(0, 0, +ratio, 0); }
    void flyDownward(double ratio)  { fly(0, 0, -ratio, 0); }
    void flyTurnLefft(double ratio) { fly(0, 0, 0, +ratio); }
    void flyTurnRight(double ratio) { fly(0, 0, 0, -ratio); }
    
};

#endif