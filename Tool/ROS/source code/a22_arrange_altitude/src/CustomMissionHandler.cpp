#include <string>

#include <Drone.h>

#include "CustomMissionHandler.h"

#include <ConcreteMission/3/DroneInALine.h>
#include <ConcreteMission/3/ArrangeStair.h>

#define state_landed 0
#define state_takingOff 1
#define state_hovering 2
#define state_flying 3
#define state_landing 4
#define state_emergency 5
#define state_userTakeOff 6
#define state_motorRamping 7
#define state_emergencyLanding 8

#define SPEED 0.5

using std::string;





void CustomMissionHandler::processCommand() {
    int command = this->command;

    if (!command) return;
    

    for (int i = 0; i < pDrone_vector.size(); ++i) {
        if (command == 48) {    // '0': takeoff
            if (pDrone_vector[i]->getFlyingState() == state_landed)
                pDrone_vector[i]->takeoff();
        } else if (command == 10) {    // 'Enter': land
            if (pDrone_vector[i]->getFlyingState() == state_hovering)
                pDrone_vector[i]->land();
        } else if (command == 46) { pDrone_vector[i]->reset(); }    // '.': reset
        else if (command == 49) { pDrone_vector[i]->flyBackwardLeftward(SPEED); }
        else if (command == 50) { pDrone_vector[i]->flyBackward(SPEED); }
        else if (command == 51) { pDrone_vector[i]->flyBackwardRightward(SPEED); }
        else if (command == 52) { pDrone_vector[i]->flyLeftward(SPEED); }
        else if (command == 53) { pDrone_vector[i]->hover(); }
        else if (command == 54) { pDrone_vector[i]->flyRightward(SPEED); }
        else if (command == 55) { pDrone_vector[i]->flyForwardLeftward(SPEED); }
        else if (command == 56) { pDrone_vector[i]->flyForward(SPEED); }
        else if (command == 57) { pDrone_vector[i]->flyForwardRightward(SPEED); }

        else if (command == 45) { pDrone_vector[i]->flyUpward(SPEED); }
        else if (command == 43) { pDrone_vector[i]->flyDownward(SPEED); }

        else if (command == 47) { pDrone_vector[i]->flyTurnLefft(SPEED); }
        else if (command == 42) { pDrone_vector[i]->flyTurnRight(SPEED); }
    }

    if (command == 113) {    // 'q': DroneInALine
        if (isOnMission) {
            printf("Is On Mission \n");
        } else {
            DroneInALine* pMission = new DroneInALine();

            pMission_vector.clear();
            pMission_vector.push_back(pMission);

            pMission->setTargetAltitude(pDrone_vector[0]->getAltitude());

            isOnMission = true;

            printf("DroneInALine Start \n");
        }
    } else if (command == 119) {    // 'w': ArrangeStair
        if (isOnMission) {
            printf("Is On Mission \n");
        } else {
            ArrangeStair* pMission = new ArrangeStair(pDrone_vector);

            pMission_vector.clear();
            pMission_vector.push_back(pMission);

            pMission->setTargetGlobalPosition(pDrone_vector);

            isOnMission = true;

            printf("ArrangeStair Start \n");
        }
    } else if (command == 100) {
        ArrangeStair* pMission = (ArrangeStair*)pMission_vector[0];
        pMission->debugDescription();

        for (int i = 0; i < 3; ++i) {
            pDrone_vector[i]->debugDescription();
        }
    }

    this->command = 0;
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv)
: MissionHandler(argc, argv, "a22_arrange_altitude_node") {
    pDrone_vector.push_back(new Drone(pNodeHandle, "bebop1"));
    pDrone_vector.push_back(new Drone(pNodeHandle, "bebop2"));
    pDrone_vector.push_back(new Drone(pNodeHandle, "bebop3"));
}
