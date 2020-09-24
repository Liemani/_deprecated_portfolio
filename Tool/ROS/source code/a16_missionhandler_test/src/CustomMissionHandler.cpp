#include <stdio.h>    // printf()

#include "CustomMissionHandler.h"
#include "Mission/FlyToPoint.h"

#define state_noMission 0
#define state_onMission 1





void CustomMissionHandler::processCommand() {
    if (*pCommand == 0) return;

    if (*pCommand == 113) {    // 'q': set mission
        if (isOnMission == state_noMission) {
            if (pMission_vector.size() == 1) {
                delete pMission_vector[0];
                pMission_vector.clear();
            }

            FlyToPoint* pFlyToPoint = new FlyToPoint;
            pMission_vector.push_back(pFlyToPoint);
            pDrone_vector[0]->setMission(pFlyToPoint);

            printf("New Custom Mission Has Enrolled!!");
        }
    } else if (*pCommand == 115) {    // 's': save current location
        if (isOnMission == state_onMission) {
            printf("You can't save location on mission! \n");
        } else if (pDrone_vector[0]->isReady() == false) {
            printf("Drone not yet ready! \n");
        } else {
            FlyToPoint* pFlyToPoint = (FlyToPoint*)pMission_vector[0];
            pFlyToPoint->targetGlobalPosition = pDrone_vector[0]->getGlobalPosition();

            printf("================ \n");
            printf("Location Saved!! \n");
            printf("  Latitude : %0.12f \n", pFlyToPoint->targetGlobalPosition.latitude);
            printf("  Longitude: %0.12f \n", pFlyToPoint->targetGlobalPosition.longitude);
            printf("  Altitude : %0.12f \n", pFlyToPoint->targetGlobalPosition.altitude);
            printf("Cartesian Coordinate \n");
            printf("  x: %0.12f \n", pDrone_vector[0]->getMatchingX());
            printf("  y: %0.12f \n", pDrone_vector[0]->getMatchingY());
            printf("  z: %0.12f \n", pDrone_vector[0]->getMatchingZ());
            printf("------------------------- \n");
        }
    } else if (*pCommand == 119) {    // 'w': perform mission
        isOnMission = state_onMission;
    } else if (*pCommand == 99) {    // 'c': print debug
        pMission_vector[0]->debugDescription();
    }

    *pCommand = 0;
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv, int* pCommand)
: MissionHandler(argc, argv, "a16_missionhandler_test_node", pCommand) {
    pDrone_vector.push_back(new Drone(pNodeHandle));
}