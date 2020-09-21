#ifndef MISSIONHANDLER_H
#define MISSIONHANDLER_H

#include "Drone.h"





class Drone;

class MissionHandler {
    ros::NodeHandle* pNodeHandle;
    int* pCommand;

    std::vector<Drone*> pDrone_vector;
    std::vector<Mission*> pMission_vector;

    int missionState;

public:
    MissionHandler(ros::NodeHandle* pNodeHandle, int* pCommand);

    void loop();
    
    void processCommand();
    void doMission();
    void debugDescription();

};

#endif