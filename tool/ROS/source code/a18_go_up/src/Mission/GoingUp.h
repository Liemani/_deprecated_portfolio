#ifndef GOINGUP_H
#define GOINGUP_H

#include <vector>

#include <CoreMission.h>





class Drone;

typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class GoingUp: public CoreMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

public:
    GoingUp();

    virtual bool perform(Drone* pDrone);
    
    void saveTargetPosition(double targetAltitude);

    double targetAltitude;

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
