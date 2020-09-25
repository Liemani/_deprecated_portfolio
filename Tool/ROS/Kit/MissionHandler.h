#ifndef MISSIONHANDLER_H
#define MISSIONHANDLER_H

#include <string>
#include <vector>

#include "Drone.h"
#include "Mission.h"





class Drone;
class Mission;

class MissionHandler {
protected:
    int command;

    ros::NodeHandle* pNodeHandle;

    bool isOnMission;

    std::vector<Drone*> pDrone_vector;
    std::vector<Mission*> pMission_vector;
    
    virtual void processCommand();    // must virtual for to use derived class's function in the loop function
    void perform();
    // virtual void debugDescription();

public:
    MissionHandler(int argc, char** argv, std::string nodeName);

    void loop();

    int* getPCommand();

};

#endif
