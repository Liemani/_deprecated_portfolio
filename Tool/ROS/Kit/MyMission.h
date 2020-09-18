#ifndef MYMISSION_H
#define MYMISSION_H

#include <stdio.h>
#include <math.h>

#include "GlobalPosition.h"
#include "CartesianCoordinate.h"
#include "Mission.h"





typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class MyMission: public Mission {
    // callback function
    static void callWhenPositionChanged(Mission* mission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* mission, Drone& drone);
    static void callWhenBearingChanged(Mission* mission, Drone& drone);

    GlobalPosition targetGlobalPosition;

    // mission variable
    double targetPlaneDistance;
    double targetDistance;
    double targetAngle;

    CartesianCoordinate targetCartesianCoordinate;

    // private static function
    void calculateTargetCartesianCoordinateXY(Drone& drone);
    void calculateTargetCartesianCoordinateZ(Drone& drone);
    void calculateTargetDistance(Drone& drone);

public:
    MyMission(GlobalPosition& targetGlobalPosition);

    virtual bool perform(std::vector<Drone*>& pDrone_vector);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
