#include <stdio.h>
#include <vector>

#include <Drone.h>
#include <GlobalPosition.h>
#include <CoreMission/FlyToPoint.h>

#include "ArrangeStair.h"

#define DRONE_COUNT 3

using std::vector;





// callback function
void ArrangeStair::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void ArrangeStair::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void ArrangeStair::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
ArrangeStair::ArrangeStair(vector<Drone*>& pDrone_vector)
: ConcreteMission() {
    for (int i = 0; i < DRONE_COUNT; ++i) {
        pMission_vector.push_back(new FlyToPoint);
        pDrone_vector[i]->setMission(pMission_vector[i]);
    }
}

// return value:
//  true: end this mission
//  false: on going
bool ArrangeStair::perform(vector<Drone*>& pDrone_vector) {
    for (int i = 0; i < DRONE_COUNT; ++i) {
        if (!pMission_vector[i]->isReady()) {
            printf("Waiting Mission \n");
            return false;
        }
    }
    
    bool shouldEnd = true;

    for (int i = 0; i < DRONE_COUNT; ++i)
        shouldEnd &= pMission_vector[i]->perform(pDrone_vector[i]);

    if (shouldEnd) {
        for (int i = 0; i < DRONE_COUNT; ++i) {
            pDrone_vector[i]->removeMission();
        }

        printf("Mission End \n");

        return true;
    } else {
        return false;
    }
}

void ArrangeStair::debugDescription() {
    printf("====================");
    for (int i = 0; i < DRONE_COUNT; ++i) {
        pMission_vector[i]->debugDescription();
    }
}

void ArrangeStair::setTargetGlobalPosition(std::vector<Drone*> pDrone_vector) {
    for (int i = 0; i < DRONE_COUNT; ++i) {
        GlobalPosition position = pDrone_vector[i]->getGlobalPosition();
        position.altitude += 0.5 * i;
        pMission_vector[i]->setTargetGlobalPosition(position);
    }
}
