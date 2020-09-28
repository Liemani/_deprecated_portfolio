#include <stdio.h>
#include <string>

#include <Drone.h>
#include <ConcreteMission/3/DroneInALine.h>

#include "CustomMissionHandler.h"

#define SPEED 0.5

using std::string;





void CustomMissionHandler::processCommand() {
    if (!command) return;

    if (command == '0') {    // takeoff
        for (int i = 0; i != pDrone_vector.size(); ++i)
            pDrone_vector[i]->takeoff();
    } else if (command == '-') {    // fly upward
        for (int i = 0; i != pDrone_vector.size(); ++i)
            pDrone_vector[i]->flyUpward(SPEED);
    } else if (command == '+') {    // fly downward
        for (int i = 0; i != pDrone_vector.size(); ++i)
            pDrone_vector[i]->flyDownward(SPEED);
    } else if (command == 'd') {    // print altitude
        for (int i = 0; i != pDrone_vector.size(); ++i) {
            pDrone_vector[i]->debugGlobalPosition();
            printf("Altitude%d: %12.8f \n", i + 1, pDrone_vector[i]->getAltitude());
        }
        
        printf("---------------------------- \n");
    } else if (command == 's') {    // 's' save current altitude
        DroneInALine* pMission = (DroneInALine*)pMission_vector[0];
        double targetAltitude = pDrone_vector[1]->getAltitude();

        pMission->setTargetAltitude(targetAltitude);
        printf("Altitude Saved: %12.8f \n", targetAltitude);
        printf("---------------------------- \n");
    } else if (command == ' ') {    // ' ': start mission
        printf("Mission Start \n");
        printf("------------- \n");
        isOnMission = true;
    }

    command = 0;
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv)
: MissionHandler(argc, argv, "a20_drone_in_a_line_node") {
    pDrone_vector.push_back(new Drone(pNodeHandle, "bebop1"));
    pDrone_vector.push_back(new Drone(pNodeHandle, "bebop2"));
    pDrone_vector.push_back(new Drone(pNodeHandle, "bebop3"));

    pMission_vector.push_back(new DroneInALine());
}
