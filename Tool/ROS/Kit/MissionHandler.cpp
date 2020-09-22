#include <ros/ros.h>
#include "MissionHandler.h"

#define state_noMission 0
#define state_onMission 1





// protected member function
void MissionHandler::processCommand() {

}

void MissionHandler::perform() {
    if (missionState != state_onMission) return;

    static bool shouldStop;
    shouldStop = true;
    
    for (std::vector<Mission*>::iterator iter = pMission_vector.begin(); iter != pMission_vector.end(); ++iter)
        shouldStop &= (*iter)->perform(pDrone_vector);
    
    if (shouldStop)
        missionState = state_noMission;
}

// void MissionHandler::debugDescription() {

// }





// public member function
MissionHandler::MissionHandler(int argc, char** argv, char* nodeName, int* pCommand) {
    ros::init(argc, argv, nodeName);
    this->pCommand = pCommand;

    pNodeHandle = new ros::NodeHandle;

    missionState = state_noMission;
}

void MissionHandler::loop() {
    while(ros::ok()) {
        this->processCommand();
        this->perform();
    }
}
