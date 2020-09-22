#ifndef MISSIONHANDLER_H
#define MISSIONHANDLER_H

#include <vector>

#include "Drone.h"
#include "Mission.h"





class Drone;
class Mission;

class MissionHandler {
protected:
    int* pCommand;

    ros::NodeHandle* pNodeHandle;

    int missionState;

    std::vector<Drone*> pDrone_vector;
    std::vector<Mission*> pMission_vector;
    
    void processCommand();
    void perform();
    // void debugDescription();

public:
    MissionHandler(int argc, char** argv, char* nodeName, int* pCommand);

    void loop();

};

#endif
