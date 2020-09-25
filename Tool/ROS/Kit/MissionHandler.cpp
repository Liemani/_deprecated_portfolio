#include <ros/ros.h>

#include <string>

#include "MissionHandler.h"

#include "CoreMission.h"
#include "ConcreteMission.h"

using std::string;





// protected member function
void MissionHandler::processCommand() {

}

void MissionHandler::perform() {
    if (!isOnMission) return;

    bool shouldStop = true;
    
    for (std::vector<Mission*>::iterator iter = pMission_vector.begin(); iter != pMission_vector.end(); ++iter) {
        CoreMission* coreMission = dynamic_cast<CoreMission*>(*iter);
        ConcreteMission* concreteMission = dynamic_cast<ConcreteMission*>(*iter);

        if (coreMission) {
            shouldStop &= coreMission->perform(pDrone_vector[0]);
        } else if (concreteMission) {
            shouldStop &= concreteMission->perform(pDrone_vector);
        }
    }
    
    if (shouldStop)
        isOnMission = false;
}

// void MissionHandler::debugDescription() {

// }





// public member function
MissionHandler::MissionHandler(int argc, char** argv, string nodeName) {
    ros::init(argc, argv, nodeName);

    command = 0;

    pNodeHandle = new ros::NodeHandle;

    isOnMission = false;
}

void MissionHandler::loop() {
    while(ros::ok()) {
        ros::spinOnce();

        this->processCommand();
        this->perform();
    }
}

int* MissionHandler::getPCommand() {
    return &command;
}
