#include <vector>

#include "../Drone.h"

#include "FlyToTargetAltitude.h"

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





FlyToTargetAltitude::FlyToTargetAltitude()
: CoreMission(){
    // initializing code goes here...
}


// public
// return value:
//  true: end this mission
//  false: on going
int cnt;
bool FlyToTargetAltitude::perform(Drone* pDrone) {
    // perform code goes here...
    currentAltitude = pDrone->getAltitude();

    if(currentAltitude < (targetAltitude *0.95)) {
        pDrone->flyUpward(0.5);
    }
    else if(currentAltitude > (targetAltitude *1.05)){
        pDrone->flyDownward(0.5);
    }
    else {
        printf("Complete The Mission1");
        return true;
    }
    return false;
}

void FlyToTargetAltitude::debugDescription() {
    // code goes here...
}

