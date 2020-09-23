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

    bool isOnMission;

    std::vector<Drone*> pDrone_vector;
    std::vector<Mission*> pMission_vector;
    
    virtual void processCommand();    // must virtual for to use derived class's function in the loop function
    void perform();
    // void debugDescription();

public:
    MissionHandler(int argc, char** argv, char* nodeName, int* pCommand);

    void loop();

};

#endif
