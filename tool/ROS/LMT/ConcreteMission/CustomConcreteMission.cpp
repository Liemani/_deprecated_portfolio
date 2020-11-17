#include <vector>

#include <Drone.h>

#include "CustomConcreteMission.h"

using std::vector;





// callback function
void CustomConcreteMission::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CustomConcreteMission::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CustomConcreteMission::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
CustomConcreteMission::CustomConcreteMission()
: ConcreteMission() {
    // initializing code goes here...
}

// return value:
//  true: end this mission
//  false: on going
bool CustomConcreteMission::perform(vector<Drone*> pDrone_vector) {
    // perform code goes here...

    return true;
}

void CustomConcreteMission::debugDescription() {
    // code goes here...
}
