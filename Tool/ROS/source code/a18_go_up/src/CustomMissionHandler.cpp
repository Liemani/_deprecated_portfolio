#include <string>

#include <Drone.h>

#include "CustomMissionHandler.h"
#include "Mission/GoingUp.h"

using std::string;





void CustomMissionHandler::processCommand() {
    if (command == 's') {    // 's': save position
        GoingUp* goingUp = (GoingUp*)pMission_vector[0];

        goingUp->saveTargetPosition(pDrone_vector[0]->getAltitude());
    } else if (command == ' ') {    // ' ': perform mission
        isOnMission = true;
    }

    command = 0;
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv)
: MissionHandler(argc, argv, "a18_go_up_node") {
    pDrone_vector.push_back(new Drone(pNodeHandle));
    pMission_vector.push_back(new GoingUp);
    
    // If you want to link mission to drone(mission's callback function will be adjusted),
    // you must call drone.setMission(mission).
    // One Drone only can hold 1 mission.
    pDrone_vector[0]->setMission(pMission_vector[0]);
}
