#ifndef FLYTOPOINT_H
#define FLYTOPOINT_H

#include <vector>

#include <CoreMission.h>




typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class Drone;
class Mission;

class FlyToPoint: public CoreMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

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

    virtual bool perform(Drone* pDrone);

    void debugDescription();

    GlobalPosition targetGlobalPosition;

    void setTargetGlobalPosition(GlobalPosition targetGlobalPosition);

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif