#include <Drone.h>

#include "MoveToThePoint.h"

using std::vector;

#define BEARINGSPEED 0.15
#define YAWDAEDLINE 0.01
#define DISTANCEDAEDLINE 0.01
#define LINERSPEED 0.3




// callback function
void MoveToThePoint::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void MoveToThePoint::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}

void MoveToThePoint::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// public
MoveToThePoint::MoveToThePoint()
: CoreMission() {
    // initializing code goes here...
}

// return value:
//  true: end this mission
//  false: on going
bool isBearingReady = false;
bool isArrived = false;

bool MoveToThePoint::perform(Drone* pDrone) {
    // perform code goes here...
    //targetBearing 찾기
    targetBearing = findTargetBearing(pDrone->getLatitude(),pDrone->getLongitude(),targetLatitude,targetLongitude);
    currentBearing = pDrone->getBearing();
    gapOfBearing_ = gapOfBearing(currentBearing,targetBearing);
    distance_ = distance(pDrone->getLatitude(),pDrone->getLongitude(),targetLatitude,targetLongitude);

    if(isBearingReady == false) {
        //targetBearing으로 돌기
        if (0 < gapOfBearing_)
            pDrone->flyTurnLefft(BEARINGSPEED);
        else if (gapOfBearing_ < 0)
            pDrone->flyTurnRight(BEARINGSPEED);

        if (-YAWDAEDLINE < gapOfBearing_ && gapOfBearing_ < YAWDAEDLINE)
            isBearingReady = true;
    }
    //전진하고
    if(isBearingReady == true && isArrived == false){
        if( 0 < distance_)
            pDrone->flyForward(BEARINGSPEED);
        else if (distance_ < 0)
            pDrone->flyBackward(BEARINGSPEED);

        if (-LINERSPEED < distance_ && distance_ < LINERSPEED)
            isArrived = true;
    }
    return true;
}

void MoveToThePoint::debugDescription() {
    // code goes here...
}

double MoveToThePoint::distance(double Latitude, double Longitude, double targetLatitude, double targetLongitude) {

    double lat_rad = (Latitude * 3.141592 / 180);
    double t_lat_rad = (targetLatitude * 3.141592 / 180);
    double lon_rad = (Longitude * 3.141592 / 180);
    double t_lon_rad = (targetLongitude * 3.141592 / 180);
    double lon_diff_rad = ((targetLongitude - Longitude) * 3.141592 / 180);


    double distance = sin(lat_rad) * sin(t_lat_rad) + cos(lat_rad) * cos(t_lat_rad) * cos(lon_diff_rad);
    distance = acos(distance);
    distance = distance *180 / 3.141592;
    distance = distance *60 * 1.515;
    distance = distance * 1.609344 * 1000;
    return distance;

}

double MoveToThePoint::findTargetBearing(double Latitude, double Longitude, double targetLatitude, double targetLongitude) {

    double lat_rad = (Latitude * 3.141592 / 180);
    double t_lat_rad = (targetLatitude * 3.141592 / 180);
    double lon_diff_rad = ((targetLongitude - Longitude) * 3.141592 / 180);

    double y = sin(lon_diff_rad) * cos(t_lat_rad);
    double x = cos(lat_rad) * sin(t_lat_rad) - sin(lat_rad) * cos(t_lat_rad) * cos(lon_diff_rad);

    return atan2(y, x);

}

double MoveToThePoint::gapOfBearing(double currentBearing, double targetBearing) {
    double gapOfBearing = currentBearing - targetBearing;
    if(gapOfBearing > 3.14)
        gapOfBearing =  gapOfBearing - 6.28;
    else if(gapOfBearing < -3.14)
        gapOfBearing = 6.28 + gapOfBearing;

    return gapOfBearing;
}