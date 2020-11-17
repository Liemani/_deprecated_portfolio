#ifndef KEEPCROSSMOVING_H
#define KEEPCROSSMOVING_H

#include <vector>

#include <ConcreteMission.h>

#include <CoreMission/FlyToTargetAltitude.h>



class Drone;

typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class KeepCrossMoving: public ConcreteMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

public:
    KeepCrossMoving();

    std::vector<FlyToTargetAltitude*> pMission_vector;
    void setTargetAltitude(double targetAltitude);  // FlyToTargetAltitude 받아온 정보를 저장한다.

    bool perform(std::vector<Drone*>& pDrone_vector);
    bool is_left_higher;
    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
