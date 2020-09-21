#include "MyMission.h"

#define PI 3.141592
#define RADIUS_OF_EARTH 6371

#define SPEED 0.5





// callback function
void MyMission::callWhenPositionChanged(Mission* pMission, Drone& drone) {
    MyMission* pMyMission = (MyMission*)pMission;

    pMyMission->calculateTargetCartesianCoordinateXY(drone);
}

void MyMission::callWhenAltitudeChanged(Mission* pMission, Drone& drone) {
    MyMission* pMyMission = (MyMission*)pMission;
    
    pMyMission->calculateTargetCartesianCoordinateZ(drone);
}

void MyMission::callWhenBearingChanged(Mission* pMission, Drone& drone) {
    // code goes here...
}





// private member function
void MyMission::calculateTargetCartesianCoordinateXY(Drone& drone) {
    const double latitudeA = drone.getLatitude() / 180 * PI;
    const double longitudeA = drone.getLongitude() / 180 * PI;

    const double latitudeB = targetGlobalPosition.latitude / 180 * PI;
    const double longitudeB = targetGlobalPosition.longitude / 180 * PI;

    const double deltaLatitude = latitudeB - latitudeA;
    const double deltaLongitude = longitudeB - longitudeA;



    const double a = pow(sin(deltaLatitude / 2), 2) + cos(latitudeA) * cos(latitudeB) * pow(sin(deltaLongitude / 2), 2);
    const double distance = RADIUS_OF_EARTH * (2 * atan2(sqrt(a), sqrt(1 - a))) * 1000;



    const double X = cos(latitudeB) * sin(deltaLongitude);
    const double Y = cos(latitudeA) * sin(latitudeB) - sin(latitudeA) * cos(latitudeB) * cos(deltaLongitude);
    const double targetBearing = atan2(X, Y);

    targetCartesianCoordinate.x = drone.getMatchingX() + distance * cos(targetBearing);
    targetCartesianCoordinate.y = drone.getMatchingY() + distance * sin(-targetBearing);

    calculateTargetDistance(drone);
}

void MyMission::calculateTargetCartesianCoordinateZ(Drone& drone) {
    targetCartesianCoordinate.z = drone.getMatchingZ() - drone.getAltitude() + targetGlobalPosition.altitude;
}

void MyMission::calculateTargetDistance(Drone& drone) {
    const double delta_x = targetCartesianCoordinate.x - drone.getOdometryX();
    const double delta_y = targetCartesianCoordinate.y - drone.getOdometryY();
    const double delta_z = targetCartesianCoordinate.z - drone.getOdometryZ();

    targetPlaneDistance = sqrt(pow(delta_x, 2.0) + pow(delta_y, 2.0));
    targetDistance = sqrt(pow(targetPlaneDistance, 2.0) + pow(delta_z, 2.0));

    targetAngle = drone.getBearing() + atan2((targetCartesianCoordinate.y - drone.getOdometryY()), (targetCartesianCoordinate.x - drone.getOdometryX()));
}





MyMission::MyMission(GlobalPosition& targetGlobalPosition) {
    this->targetGlobalPosition = targetGlobalPosition;
}

// return value:
//  true: end this mission
//  false: on going
bool MyMission::perform(std::vector<Drone*>& pDrone_vector) {
    // if drone number is not 1, end mission
    if (pDrone_vector.size() != 1) return true;

    calculateTargetDistance(*pDrone_vector[0]);

    const double ratioX = cos(targetAngle) / targetDistance * targetPlaneDistance;
    const double ratioY = sin(targetAngle) / targetDistance * targetPlaneDistance;
    const double ratioZ = (targetCartesianCoordinate.z - pDrone_vector[0]->getOdometryZ()) / targetDistance;

    if (targetDistance > 1) {
        pDrone_vector[0]->fly(SPEED * ratioX, SPEED * ratioY, SPEED * ratioZ);
    } else if (targetDistance > 0.15) {
        pDrone_vector[0]->fly(targetDistance / 10 * ratioX, targetDistance / 10 * ratioY, targetDistance * ratioZ);
    } else {
        pDrone_vector[0]->hover();
        return true;
    }

    return false;
}

void MyMission::debugDescription() {
    printf("MyMission dscription \n");
    printf("Target global position \n");
    printf("  latitude  : %0.12f \n", targetGlobalPosition.latitude);
    printf("  longitude : %0.12f \n", targetGlobalPosition.longitude);
    printf("  altitude  : %0.12f \n", targetGlobalPosition.altitude);
    printf("Target cartesian coordinate \n");
    printf("  x: %0.12f \n", targetCartesianCoordinate.x);
    printf("  y: %0.12f \n", targetCartesianCoordinate.y);
    printf("  z: %0.12f \n", targetCartesianCoordinate.z);
    printf("Target distance: %0.12f \n", targetDistance);
    printf("Target angle: %0.12f \n", targetAngle / PI * 180);
    // printf("Target global position \n");
    // printf("  latitude  : %0.12f \n", targetGlobalPosition.latitude);
    // printf("  longitude : %0.12f \n", targetGlobalPosition.longitude);
    // printf("  altitude  : %0.12f \n", targetGlobalPosition.altitude);
    printf("-------------------------- \n");
}
