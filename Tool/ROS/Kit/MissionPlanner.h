#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H

#include <ros/ros.h>
#include <stdio.h>    // getchar()
#include <math.h>

#include "Drone.h"
#include "GlobalPosition.h"





using std::vector;





class Drone;





class MissionPlanner {
private:
    std::vector<Drone*> pDrone_vector;

    ros::NodeHandle* pNodeHandle;

    int missionState;

    GlobalPosition targetGlobalPosition;

    bool (*mission)(MissionPlanner& planner, std::vector<Drone*>& droneVector);

public:
    MissionPlanner(int argc, char** argv, ros::NodeHandle* pNodeHandle);

    double getTargetLatitude();
    double getTargetLongitude();
    double getTargetAltitude();

    bool processCommand(int command);
    void doMission();
    void debugDescription();

    // mission variable
    double latitudeA;
    double longitudeA;
    double latitudeB;
    double longitudeB;
    double deltaLatitude;
    double deltaLongitude;

    double a;
    double distance;

    double X;
    double Y;
    double directionAngle;

    double targetOdometryX;
    double targetOdometryY;

};

static void callWhenPositionChanged(MissionPlanner& planner);

// mission
static bool flyToTargetPosition_1(MissionPlanner& planner, std::vector<Drone*>& droneVector);

#endif