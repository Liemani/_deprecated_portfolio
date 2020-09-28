#include <stdio.h>
#include <vector>

#include <Drone.h>
#include <CoreMission/FlyToTargetAltitude.h>

#include "DroneInALine.h"

#define DRONE_COUNT 3

using std::vector;





// callback function
void DroneInALine::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void DroneInALine::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void DroneInALine::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
DroneInALine::DroneInALine(std::vector<Drone*>& pDrone_vector)
: ConcreteMission() {
    for (int i = 0; i < DRONE_COUNT; ++i)
        pMission_vector.push_back(new FlyToTargetAltitude);
}

// return value:
//  true: end this mission
//  false: on going
bool DroneInALine::perform(vector<Drone*>& pDrone_vector) {
    bool shouldStop = true;

    for (int i = 0; i < DRONE_COUNT; ++i)
        shouldStop &= pMission_vector[i]->perform(pDrone_vector[i]);

    if (shouldStop) {
        printf("Mission End \n");
        return true;
    } else {
        return false;
    }
}

void DroneInALine::debugDescription() {
    // code goes here...
}

void DroneInALine::setTargetAltitude(double targetAltitude) {
    for (int i = 0; i < DRONE_COUNT; ++i)
        pMission_vector[i]->targetAltitude = targetAltitude;
}
