#include "Mission.h"





// callback function
void Mission::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void Mission::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void Mission::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

// return value:
//  true: end this mission
//  false: on going
bool Mission::perform(std::vector<Drone*>& pDrone_vector) {
    // code goes here...

    return true;
}

void Mission::debugDescription() {
    // code goes here...
}