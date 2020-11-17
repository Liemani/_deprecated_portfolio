#include <stdio.h>
#include <vector>
#include <math.h>

#include <Drone.h>

#include "GoingUp.h"

#define SPEED 0.5

using std::vector;





// callback function
void GoingUp::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void GoingUp::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void GoingUp::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
GoingUp::GoingUp()
: CoreMission() {
    // initializing code goes here...
}

// return value:
//  true: end this mission
//  false: on going
bool GoingUp::perform(Drone* pDrone) {
    double altitudeDifference = targetAltitude - pDrone->getAltitude();

    if (altitudeDifference > 0.5) {
        pDrone->flyUpward(SPEED);
    } else if (altitudeDifference < -0.5) {
        pDrone->flyDownward(SPEED);
    } else {
        pDrone->hover();
        return true;
    }

    return false;
}

void GoingUp::saveTargetPosition(double targetAltitude) {
    this->targetAltitude = targetAltitude + 1;
}

void GoingUp::debugDescription() {
    // code goes here..
}
