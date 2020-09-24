#include <ros/ros.h>

#include <string>

#include "MissionHandler.h"

using std::string;





// protected member function
void MissionHandler::processCommand() {

}

void MissionHandler::perform() {
    if (!isOnMission) return;

    static bool shouldStop;
    shouldStop = true;
    
    for (std::vector<Mission*>::iterator iter = pMission_vector.begin(); iter != pMission_vector.end(); ++iter)
        shouldStop &= (*iter)->perform(pDrone_vector);
    
    if (shouldStop)
        isOnMission = false;
}

// void MissionHandler::debugDescription() {

// }





// public member function
MissionHandler::MissionHandler(int argc, char** argv, string nodeName, int* pCommand) {
    ros::init(argc, argv, nodeName);
    
    this->pCommand = pCommand;

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
