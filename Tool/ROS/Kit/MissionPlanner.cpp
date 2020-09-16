#include "MissionPlanner.h"

#define PI 3.141592
#define RADIUS_OF_EARTH 6371

#define RATIO 0.5
#define SLOW_RATIO 0.05

#define state_landed 0
#define state_takingOff 1
#define state_hovering 2
#define state_flying 3
#define state_landing 4
#define state_emergency 5
#define state_userTakeOff 6
#define state_motorRamping 7
#define state_emergencyLanding 8

#define state_noMission 0
#define state_onMission 1





using std::string;





MissionPlanner::MissionPlanner(int argc, char** argv, ros::NodeHandle* pNodeHandle) {
    ros::init(argc, argv, "a13_mission_planner_node2");    // node name
    this->pNodeHandle = pNodeHandle;

    missionState = state_noMission;

    pDrone_vector.push_back(new Drone(*this, pNodeHandle, "bebop", callWhenPositionChanged));
}

double MissionPlanner::getTargetLatitude() {
    return targetGlobalPosition.latitude;
}

double MissionPlanner::getTargetLongitude() {
    return targetGlobalPosition.longitude;
}

double MissionPlanner::getTargetAltitude() {
    return targetGlobalPosition.altitude;
}



// return:
//  true: key did used
//  false: key didn't used
bool MissionPlanner::processCommand(int command) {
    switch(command) {
        case 122:    // save current position of first drone to savedGlobalPosition
            targetGlobalPosition = pDrone_vector[0]->getGlobalPosition();
            ROS_INFO("Position Saved!!");

            return true;
        case 120:    // move to savedGlobalPosition
            mission = flyToTargetPosition_1;
            missionState = state_onMission;

            return true;
        case 99:    // print debug description
            debugDescription();

            return true;
        default:
            return false;
    }
}

void MissionPlanner::doMission() {
    if (missionState == state_onMission) {
        if (mission(*this, pDrone_vector)) missionState = state_noMission;
    }
}

void MissionPlanner::debugDescription() {
    for (int i = 0; i < pDrone_vector.size(); ++i) {
        printf("Name: %s \n", pDrone_vector[i]->getName().c_str());
        printf("\n");
        printf("Latitude:  %.12f \n", pDrone_vector[i]->getGlobalPosition().latitude);
        printf("Longitude: %.12f \n", pDrone_vector[i]->getGlobalPosition().longitude);
        printf("Altitude:  %.12f \n", pDrone_vector[i]->getGlobalPosition().altitude);
        printf("Bearing: %.12f \n", pDrone_vector[i]->getBearing());
        printf("\n");
        printf("Flying state: %d \n", pDrone_vector[i]->getFlyingState());
        printf("----------------------- \n");
    }
}





static void callWhenPositionChanged(MissionPlanner& planner, Drone& drone) {
    planner.latitudeA = dronegetLatitude() / 180 * PI;
    planner.longitudeA = dronegetLongitude() / 180 * PI;

    planner.latitudeB = planner.getTargetLatitude() / 180 * PI;
    planner.longitudeB = planner.getTargetLongitude() / 180 * PI;

    planner.deltaLatitude = planner.latitudeB - planner.latitudeA;
    planner.deltaLongitude = planner.longitudeB - planner.longitudeA;



    planner.a = pow(sin(planner.deltaLatitude / 2), 2) + cos(planner.latitudeA) * cos(planner.latitudeB) * pow(sin(planner.deltaLongitude / 2), 2);
    planner.distance = RADIUS_OF_EARTH * (2 * atan2(sqrt(planner.a), sqrt(1 - planner.a))) * 1000;



    planner.X = cos(planner.latitudeB) * sin(planner.deltaLongitude);
    planner.Y = cos(planner.latitudeA) * sin(planner.latitudeB) - sin(planner.latitudeA) * cos(planner.latitudeB) * cos(planner.deltaLongitude);
    planner.directionAngle = dronegetBearing() - atan2(planner.X, planner.Y);

    planner.targetOdometryX = dronegetMatchingX() + distance * cos(directionAngle);
    planner.targetOdometryY = dronegetMatchingY() + distance * sin(directionAngle);
}





// mission
// return:
//  true: mission ended
//  false: on mission
bool flyToTargetPosition_1(MissionPlanner& planner, vector<Drone*>& pDrone_vector) {
    if (pDrone_vector.size() != 1) return true;

    
    planner.targetOdometryZ = pDrone_vector[0]->getMatchingZ() - pDrone_vector[0]->getAltitude() + planner.getTargetAltitude();



    if (distance > 5) {
        pDrone_vector[0]->fly(RATIO * cos(directionAngle), RATIO * sin(directionAngle), (planner.getSavedGlobalPosition().altitude - pDrone_vector[0]->getGlobalPosition().altitude) / distance * RATIO, 0.0);
    } else if (distance > 0.05) {
        pDrone_vector[0]->fly(SLOW_RATIO * cos(directionAngle), SLOW_RATIO * sin(directionAngle), (planner.getSavedGlobalPosition().altitude - pDrone_vector[0]->getGlobalPosition().altitude) / distance * SLOW_RATIO, 0.0);
    } else {
        return true;
    }

    return false;
}
