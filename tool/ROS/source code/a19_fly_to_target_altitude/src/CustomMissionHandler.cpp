#include <stdio.h>
#include <string>

#include <Drone.h>

#include "CustomMissionHandler.h"
#include <CoreMission/FlyToTargetAltitude.h>

#define SPEED 0.5

using std::string;





void CustomMissionHandler::processCommand() {
    if (!command) return;

    if (command == '0') {    // takeoff
        pDrone_vector[0]->takeoff();
    } else if (command == '-') {    // fly upward
        pDrone_vector[0]->flyUpward(SPEED);
    } else if (command == '+') {    // fly downward
        pDrone_vector[0]->flyDownward(SPEED);
    } else if (command == 'd') {    // print altitude
        printf("Altitude: %16.12f \n", pDrone_vector[0]->getAltitude());
        printf("-------------------------- \n");
    } else if (command == 's') {    // save current altitude
        FlyToTargetAltitude* pMission = (FlyToTargetAltitude*)pMission_vector[0];
        pMission->targetAltitude = pDrone_vector[0]->getAltitude();
    } else if (command == ' ') {    // start mission
        isOnMission = true;
    }

    command = 0;
}







// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv)
: MissionHandler(argc, argv, "a19_fly_to_target_altitude_node") {
    Drone* pDrone = new Drone(pNodeHandle);
    Mission* pMission = new FlyToTargetAltitude;

    pDrone_vector.push_back(pDrone);
    pMission_vector.push_back(pMission);

    pDrone->setMission(pMission);
}
