#ifndef FLYTOTARGETALTITUDE_H
#define FLYTOTARGETALTITUDE_H

#include <vector>

#include "../CoreMission.h"





class Drone;

typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class FlyToTargetAltitude: public CoreMission {
    // callback function
    static void callWhenPositionChanged(Mission* mission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* mission, Drone& drone);
    static void callWhenBearingChanged(Mission* mission, Drone& drone);
private:


public:

    FlyToTargetAltitude();
    double targetAltitude;
    double currentAltitude;

    bool perform(Drone* pDrone);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }


};

#endif
