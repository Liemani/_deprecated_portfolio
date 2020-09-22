#ifndef MISSION_H
#define MISSION_H

#include <vector>
#include "Drone.h"





class Drone;
class Mission;

typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class Mission {
    // callback function
    static void callWhenPositionChanged(Mission* mission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* mission, Drone& drone);
    static void callWhenBearingChanged(Mission* mission, Drone& drone);

protected:

public:
    virtual bool perform(std::vector<Drone*>& pDrone_vector);

    virtual void debugDescription();

    // get callback function
    virtual CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    virtual CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    virtual CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
