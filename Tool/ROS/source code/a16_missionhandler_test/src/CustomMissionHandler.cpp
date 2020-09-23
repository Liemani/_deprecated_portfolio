#include <stdio.h>    // printf()

#include "CustomMissionHandler.h"
#include "CustomMission.h"

#define state_noMission 0
#define state_onMission 1





void CustomMissionHandler::processCommand() {
    if (*pCommand == 0) return;

    if (*pCommand == 113) {    // 'q': set mission
        if (missionState == state_noMission) {
            if (pMission_vector.size() == 1) {
                delete pMission_vector[0];
                pMission_vector.clear();
            }

            CustomMission* pCustomMission = new CustomMission;
            pMission_vector.push_back(pCustomMission);
            pDrone_vector[0]->setMission(pCustomMission);

            printf("New Custom Mission Has Enrolled!!");
        }
    } else if (*pCommand == 115) {    // 's': save current location
        if (missionState == state_onMission) {
            printf("You can't save location on mission! \n");
        } else if (pDrone_vector[0]->isReady() == false) {
            printf("Drone not yet ready! \n");
        } else {
            CustomMission* pCustomMission = (CustomMission*)pMission_vector[0];
            pCustomMission->targetGlobalPosition = pDrone_vector[0]->getGlobalPosition();

            printf("================ \n");
            printf("Location Saved!! \n");
            printf("  Latitude : %0.12f \n", pCustomMission->targetGlobalPosition.latitude);
            printf("  Longitude: %0.12f \n", pCustomMission->targetGlobalPosition.longitude);
            printf("  Altitude : %0.12f \n", pCustomMission->targetGlobalPosition.altitude);
            printf("Cartesian Coordinate \n");
            printf("  x: %0.12f \n", pDrone_vector[0]->getMatchingX());
            printf("  y: %0.12f \n", pDrone_vector[0]->getMatchingY());
            printf("  z: %0.12f \n", pDrone_vector[0]->getMatchingZ());
            printf("------------------------- \n");
        }
    } else if (*pCommand == 119) {    // 'w': perform mission
        missionState = state_onMission;
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