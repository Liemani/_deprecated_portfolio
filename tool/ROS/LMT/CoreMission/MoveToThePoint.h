#ifndef CUSTOMCOREMISSION_H
#define CUSTOMCOREMISSION_H

#include <CoreMission.h>





class Drone;

typedef void (*CallWhenDroneChanged)(Mission* pMission, Drone& drone);

class MoveToThePoint: public CoreMission {
    // callback function
    static void callWhenPositionChanged(Mission* pMission, Drone& drone);
    static void callWhenAltitudeChanged(Mission* pMission, Drone& drone);
    static void callWhenBearingChanged(Mission* pMission, Drone& drone);

public:
    MoveToThePoint();

    double targetBearing;
    double currentBearing;
    double targetLatitude;
    double targetLongitude;
    double currentLatitude;
    double currentLongitude;
    double gapOfBearing_;
    double distance_;

    double gapOfBearing(double currentBearing, double targetBearing);
    double findTargetBearing(double Latitude, double Longitude, double targetLatitude, double targetLongitude);
    double distance(double Latitude, double Longitude, double targetLatitude, double targetLongitude);

    bool perform(Drone* pDrone);

    void debugDescription();

    // get callback function
    CallWhenDroneChanged getCallWhenPositionChanged() { return callWhenPositionChanged; }
    CallWhenDroneChanged getCallWhenAltitudeChanged() { return callWhenAltitudeChanged; }
    CallWhenDroneChanged getCallWhenBearingChanged() { return callWhenBearingChanged; }

};

#endif
