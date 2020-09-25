#ifndef CUSTOMCOREMISSION_H
#define CUSTOMCOREMISSION_H

#include <CoreMission.h>





class Drone;

typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class CustomCoreMission: public CoreMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

public:
    CustomCoreMission();

    bool perform(Drone* pDrone);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
