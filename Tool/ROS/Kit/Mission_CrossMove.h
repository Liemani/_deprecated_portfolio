#ifndef Mission_CrossMove_H
#define Mission_CrossMove_H

#include <stdio.h>
#include <stdlib.h>    // abs()

#include "Mission.h"

class Drone;
class Mission;

typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class Mission_CrossMove: public Mission {
    // callback function
    static void callWhenPositionChanged(Mission* mission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* mission, Drone& drone);
    static void callWhenBearingChanged(Mission* mission, Drone& drone);
    
    double target_altitude;

public:
    Mission_CrossMove(double targetAltitude);

    void mission(std::vector<Drone*>& pDrone_vector);

    virtual bool perform(std::vector<Drone*>& pDrone_vector);

    virtual void debugDescription();

    // get callback function
    virtual CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    virtual CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    virtual CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
