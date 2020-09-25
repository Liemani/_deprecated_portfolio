#ifndef ARRANGESTAIR_H
#define ARRANGESTAIR_H

#include <vector>

#include <ConcreteMission.h>

#include <CoreMission/FlyToPoint.h>





class Drone;

typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class ArrangeStair: public ConcreteMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

    std::vector<FlyToPoint*> pMission_vector;

public:
    ArrangeStair(std::vector<Drone*>& pDrone_vector);

    bool perform(std::vector<Drone*>& pDrone_vector);

    void debugDescription();

    void setTargetGlobalPosition(std::vector<Drone*> pDrone_vector);

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
