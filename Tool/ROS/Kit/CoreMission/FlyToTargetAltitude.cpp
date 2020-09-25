#include <stdio.h>    // printf()
#include <vector>

#include <Drone.h>

#include "FlyToTargetAltitude.h"

#define SPEED 0.5

using std::vector;





// callback function
void FlyToTargetAltitude::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void FlyToTargetAltitude::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void FlyToTargetAltitude::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
FlyToTargetAltitude::FlyToTargetAltitude()
: CoreMission() {
    // initializing code goes here...
}

// return value:
//  true: end this mission
//  false: on going
bool FlyToTargetAltitude::perform(Drone* pDrone) {
    double currentAltitude = pDrone->getAltitude();

    if (targetAltitude - currentAltitude > 0.3) {
        pDrone->flyUpward(SPEED);
    } else if (currentAltitude - targetAltitude > 0.3) {
        pDrone->flyDownward(SPEED);
    } else {
        printf("Fly to target altitude mission end. \n");
        return true;
    }

    return false;
}

void FlyToTargetAltitude::debugDescription() {
    // code goes here...
}

void FlyToTargetAltitude::setTargetAltitude(double targetAltitude) {
    this->targetAltitude = targetAltitude;
}
