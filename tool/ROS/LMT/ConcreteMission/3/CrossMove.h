#ifndef CROSSMOVE_H
#define CROSSMOVE_H

#include <vector>

#include <ConcreteMission.h>

#include <CoreMission/FlyToTargetAltitude.h>




class Drone;

typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class CrossMove: public ConcreteMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

public:
    CrossMove();

    std::vector<FlyToTargetAltitude*> pMission_vector;
    void setTargetAltitude(double targetAltitude);  // FlyToTargetAltitude 받아온 정보를 저장한다.

    bool perform(std::vector<Drone*>& pDrone_vector);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
