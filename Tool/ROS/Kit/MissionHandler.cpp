#include "MissionHandler.h"

#define state_noMission 0
#define state_onMission 1

MissionHandler::MissionHandler(ros::NodeHandle* pNodeHandle, int* pCommand) {
    this->pNodeHandle = pNodeHandle;
    this->pCommand = pCommand;

    missionState = 0;
}

void MissionHandler::loop() {
    this->processCommand();
    this->doMission();
}

void MissionHandler::processCommand() {

}

void MissionHandler::doMission() {
    if (missionState != state_onMission) return;

    static bool shouldStop = true;
    
    for (int i = 0; i != pMission_vector.size(); ++i)
        shouldStop &= pMission_vector[i]->perform(pDrone_vector);
    
    if (shouldStop)
        missionState = 0;
}

void MissionHandler::debugDescription() {

}
