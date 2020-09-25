#ifndef CONCRETEMISSION_H
#define CONCRETEMISSION_H

#include <vector>

#include "Mission.h"





class Mission;
class Drone;

class ConcreteMission: public Mission {

public:
    virtual bool perform(std::vector<Drone*>& pDrone_vector);
};

#endif
