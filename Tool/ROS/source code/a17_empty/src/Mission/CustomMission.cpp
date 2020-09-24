#include <vector>

#include <Drone.h>

#include "CustomMission.h"

using std::vector;





// callback function
void CustomMission::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CustomMission::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CustomMission::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
// return value:
//  true: end this mission
//  false: on going
CustomMission::CustomMission()
: Mission() {
    // initializing code goes here...
}

bool CustomMission::perform(vector<Drone*>& pDrone_vector) {
    // perform code goes here...

    return true;
}

void CustomMission::debugDescription() {
    // code goes here...
}
