#include <stdio.h>    // printf()

#include <CoreMission/FlyToPoint.h>

#include "CustomMissionHandler.h"

#define state_noMission 0
#define state_onMission 1





void CustomMissionHandler::processCommand() {
    if (command == 0) return;

    if (command == 115) {    // 's': save current location
        if (isOnMission == true) {
            printf("You can't save location during mission! \n");
        } else if (pDrone_vector[0]->isReady() == false) {
            printf("Drone not yet ready! \n");
        } else {
            FlyToPoint* pFlyToPoint = (FlyToPoint*)pMission_vector[0];
            pFlyToPoint->setTargetGlobalPosition(pDrone_vector[0]->getGlobalPosition());

            printf("================ \n");
            printf("Location Saved!! \n");
            printf("  Latitude  : %12.8f \n", pFlyToPoint->targetGlobalPosition.latitude);
            printf("  Longitude : %12.8f \n", pFlyToPoint->targetGlobalPosition.longitude);
            printf("  Altitude  : %12.8f \n", pFlyToPoint->targetGlobalPosition.altitude);
            printf("Cartesian Coordinate \n");
            printf("  x: %12.8f \n", pDrone_vector[0]->getMatchingX());
            printf("  y: %12.8f \n", pDrone_vector[0]->getMatchingY());
            printf("  z: %12.8f \n", pDrone_vector[0]->getMatchingZ());
            printf("----------------- \n");
        }
    } else if (command == 32) {    // ' ': perform mission
        isOnMission = true;
    } else if (command == 100) {    // 'd': print debug
        pMission_vector[0]->debugDescription();
    }

    command = 0;
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv)
: MissionHandler(argc, argv, "a16_missionhandler_test_node") {
    pDrone_vector.push_back(new Drone(pNodeHandle));

    FlyToPoint* pFlyToPoint = new FlyToPoint;
    pMission_vector.push_back(pFlyToPoint);

    pDrone_vector[0]->setMission(pFlyToPoint);
}
