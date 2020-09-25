#ifndef CUSTOMCONCRETEMISSION_H
#define CUSTOMCONCRETEMISSION_H

#include <vector>

#include <ConcreteMission.h>





class Drone;

typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class CustomConcreteMission: public ConcreteMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

public:
    CustomConcreteMission();

    bool perform(std::vector<Drone*> pDrone_vector);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
