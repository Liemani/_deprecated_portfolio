#include <string>

#include <Drone.h>

#include "CustomMissionHandler.h"
#include "Mission/GoingUp.h"

using std::string;





void CustomMissionHandler::processCommand() {
    if (*pCommand == 's') {    // save position
        GoingUp* goingUp = (GoingUp*)pMission_vector[0];

        goingUp->saveTargetPosition(*pDrone_vector[0]);
    } else if (*pCommand == ' ') {    // perform mission
        isOnMission = true;
    }

    *pCommand = 0;
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv, int* pCommand)
: MissionHandler(argc, argv, "a18_go_up_node", pCommand) {
    pDrone_vector.push_back(new Drone(pNodeHandle));
    pMission_vector.push_back(new GoingUp);
    
    // If you want to link mission to drone(mission's callback function will be adjusted),
    // you must call drone.setMission(mission).
    // One Drone only can hold 1 mission.
    pDrone_vector[0]->setMission(pMission_vector[0]);
}
