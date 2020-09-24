#ifndef CUSTOMMISSION_H
#define CUSTOMMISSION_H

#include <vector>

#include <Mission.h>





class Drone;

typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class CustomMission: public Mission {
    // callback function
    static void callWhenPositionChanged(Mission* mission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* mission, Drone& drone);
    static void callWhenBearingChanged(Mission* mission, Drone& drone);

public:
    CustomMission();

    bool perform(std::vector<Drone*>& pDrone_vector);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
