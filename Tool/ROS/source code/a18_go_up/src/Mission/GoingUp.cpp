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
// return value:
//  true: end this mission
//  false: on going
GoingUp::GoingUp()
: Mission() {
    // initializing code goes here...
}

bool GoingUp::perform(std::vector<Drone*>& pDrone_vector) {
    double altitudeDifference = targetAltitude - pDrone_vector[0]->getAltitude();

    if (altitudeDifference > 0.5) {
        pDrone_vector[0]->flyUpward(SPEED);
    } else if (altitudeDifference < -0.5) {
        pDrone_vector[0]->flyDownward(SPEED);
    } else {
        pDrone_vector[0]->hover();
        return true;
    }

    return false;
}

void GoingUp::saveTargetPosition(Drone& drone) {
    targetAltitude = drone.getAltitude() + 1;
}

void GoingUp::debugDescription() {
    // code goes here..
}
