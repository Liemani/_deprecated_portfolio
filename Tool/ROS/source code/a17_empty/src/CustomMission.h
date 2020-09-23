#ifndef CUSTOMMISSION_H
#define CUSTOMMISSION_H

#include <vector>

#include <Mission.h>




typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class Drone;
class Mission;

class CustomMission: public Mission {
public:
    virtual bool perform(std::vector<Drone*>& pDrone_vector);

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return NULL; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return NULL; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return NULL; }

};

#endif