#include <stdio.h>    // printf()

#include <Drone.h>

#include "CustomMissionHandler.h"
#include "GoingUp.h"





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
    
    pDrone_vector[0]->setMission(pMission_vector[0]);
}
