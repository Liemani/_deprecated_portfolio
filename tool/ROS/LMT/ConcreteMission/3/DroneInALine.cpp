#include <vector>
#include <CoreMission/FlyToTargetAltitude.h>
#include <Drone.h>
#include "DroneInALine.h"


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
DroneInALine::DroneInALine()
: ConcreteMission() {
    // initializing code goes here...
    pMission_vector.push_back(new FlyToTargetAltitude);
    pMission_vector.push_back(new FlyToTargetAltitude);
    pMission_vector.push_back(new FlyToTargetAltitude);
}

// return value:
//  true: end this mission
//  false: on going
bool DroneInALine::perform(vector<Drone*>& pDrone_vector) {
    // perform code goes here...
    bool mission1 = pMission_vector[0]->perform(pDrone_vector[0]);
    bool mission2 = pMission_vector[1]->perform(pDrone_vector[1]);
    bool mission3 = pMission_vector[2]->perform(pDrone_vector[2]);

    if(mission1 == true && mission2 == true && mission3 == true )
        return true;
    else
        return false;
}

void DroneInALine::debugDescription() {
    // code goes here...
}

void DroneInALine::setTargetAltitude(double targetAltitude) {
    pMission_vector[0]->targetAltitude = targetAltitude;
    pMission_vector[1]->targetAltitude = targetAltitude;
    pMission_vector[2]->targetAltitude = targetAltitude;
}
