#ifndef FLYTOPOINT_H
#define FLYTOPOINT_H

#include <vector>

#include <Mission.h>




typedef void (*CallWhenDroneChanged)(Mission* mission, Drone& drone);

class Drone;
class Mission;

class FlyToPoint: public Mission {
    // callback function
    static void callWhenPositionChanged(Mission* mission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* mission, Drone& drone);
    static void callWhenBearingChanged(Mission* mission, Drone& drone);

    // mission variable
    double targetPlaneDistance;
    double targetDistance;
    double targetAngle;

    CartesianCoordinate targetCartesianCoordinate;

    bool isPossibleEnd;

    // private static function
    void calculateTargetCartesianCoordinateXY(Drone& drone);
    void calculateTargetCartesianCoordinateZ(Drone& drone);
    void calculateTargetDistance(Drone& drone);

public:
    FlyToPoint();

    GlobalPosition targetGlobalPosition;

    virtual bool perform(std::vector<Drone*>& pDrone_vector);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif