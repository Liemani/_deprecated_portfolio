#include <Drone.h>

#include "CustomCoreMission.h"

using std::vector;





// callback function
void CustomCoreMission::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CustomCoreMission::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CustomCoreMission::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
CustomCoreMission::CustomCoreMission()
: CoreMission() {
    // initializing code goes here...
}

// return value:
//  true: end this mission
//  false: on going
bool CustomCoreMission::perform(Drone* pDrone) {
    // perform code goes here...

    return true;
}

void CustomCoreMission::debugDescription() {
    // code goes here...
}
