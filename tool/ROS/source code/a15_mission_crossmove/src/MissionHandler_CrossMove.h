#ifndef MISSIONHANDLER_CROSSMOVE_H
#define MISSIONHANDLER_CROSSMOVE_H

#include <ros/ros.h>
#include <stdio.h>    // getchar()

#include <Model/Drone.h>
#include <Model/GlobalPosition.h>
#include <Model/Mission.h>
#include <Model/Mission_CrossMove.h>





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
    MissionPlanner(int argc, char** argv, ros::NodeHandle* pNodeHandle, int* pCommand);

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