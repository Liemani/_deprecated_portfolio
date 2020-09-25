#ifndef COREMISSION_H
#define COREMISSION_H

#include "Mission.h"





class Mission;
class Drone;

class CoreMission: public Mission {

public:
    virtual bool perform(Drone* pDrone);
};

#endif
