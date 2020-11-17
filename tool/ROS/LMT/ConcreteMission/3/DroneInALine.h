#ifndef CUSTOMMISSION_H
#define CUSTOMMISSION_H

#include <vector>

#include <ConcreteMission.h>

#include <CoreMission/FlyToTargetAltitude.h>




class Drone;

typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class DroneInALine: public ConcreteMission {
    // callback function
    static void callWhenPositionChanged(Mission* mission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* mission, Drone& drone);
    static void callWhenBearingChanged(Mission* mission, Drone& drone);

public:
    DroneInALine();

    std::vector<FlyToTargetAltitude*> pMission_vector;

    bool perform(std::vector<Drone*>& pDrone_vector);


    void setTargetAltitude(double targetAltitude);  // FlyToTargetAltitude 받아온 정보를 저장한다.


    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
