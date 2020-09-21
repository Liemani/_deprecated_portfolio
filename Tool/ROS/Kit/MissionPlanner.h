#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H

#include <ros/ros.h>
#include <stdio.h>    // getchar()

#include "Drone.h"
#include "GlobalPosition.h"
#include "Mission.h"
#include "MyMission.h"





using std::vector;





class Drone;





class MissionPlanner {
// callback function
friend void callWhenPositionChanged(MissionPlanner& planner, Drone& drone);
friend void callWhenAltitudeChanged(MissionPlanner& planner, Drone& drone);
friend void callWhenBearingChanged(MissionPlanner& planner, Drone& drone);

private:
    int* pCommand;

    std::vector<Drone*> pDrone_vector;

    ros::NodeHandle* pNodeHandle;

    Mission* mission;

    int missionState;

    GlobalPosition targetGlobalPosition;

public:
    MissionPlanner(ros::NodeHandle* pNodeHandle, int* pCommand);

    // get set function
    double getTargetLatitude();
    double getTargetLongitude();
    double getTargetAltitude();

    void processCommand();
    void doMission();
    void debugDescription();

    void loop();

};

#endif