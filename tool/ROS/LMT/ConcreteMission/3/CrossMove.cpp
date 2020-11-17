#include <vector>
#include <Drone.h>
#include "CrossMove.h"
#include <CoreMission/FlyToTargetAltitude.h>

using std::vector;





// callback function
void CrossMove::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CrossMove::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void CrossMove::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
CrossMove::CrossMove()
: ConcreteMission()
{
    // initializing code goes here...
    pMission_vector.push_back(new FlyToTargetAltitude);
    pMission_vector.push_back(new FlyToTargetAltitude);
    pMission_vector.push_back(new FlyToTargetAltitude);
}

// return value:
//  true: end this mission
//  false: on going
bool CrossMove::perform(vector<Drone*>& pDrone_vector) {
    // perform code goes here...
    printf("Doing Mission1\n");
    bool mission1 = pMission_vector[0]->perform(pDrone_vector[0]);
    printf("Doing Mission1\n");
    bool mission2 = pMission_vector[1]->perform(pDrone_vector[1]);
    printf("Doing Mission2\n");
    bool mission3 = pMission_vector[2]->perform(pDrone_vector[2]);
    printf("Doing Mission3\n");

    if(mission1 == true && mission2 == true && mission3 == true ) {
        printf("Done!\n");
        setTargetAltitude(pDrone_vector[1]->getAltitude());
    }
    return false;
}

void CrossMove::debugDescription() {
    // code goes here...
}

bool is_left_higher = false;
void CrossMove::setTargetAltitude(double targetAltitude)
{
    if(is_left_higher == false){
        pMission_vector[0]->targetAltitude = targetAltitude + 1;
        pMission_vector[1]->targetAltitude = targetAltitude;
        pMission_vector[2]->targetAltitude = targetAltitude - 1;
        printf(" \\ \n");
        is_left_higher = true;
    }
    else if(is_left_higher == true){
        pMission_vector[0]->targetAltitude = targetAltitude - 1;
        pMission_vector[1]->targetAltitude = targetAltitude;
        pMission_vector[2]->targetAltitude = targetAltitude + 1;
        printf(" / \n");
        is_left_higher = false;
    }
}
