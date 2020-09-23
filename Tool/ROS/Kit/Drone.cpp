#include "Drone.h"

#define QUEUE_SIZE 1

using std::string;





Drone::Drone(ros::NodeHandle* pNodeHandle,std::string name) {
    this->name = name;

    this->pMission = NULL;

    callWhenPositionChanged = NULL;
    callWhenAltitudeChanged = NULL;
    callWhenBearingChanged = NULL;

    positionSub = pNodeHandle->subscribe(name + "/states/ardrone3/PilotingState/PositionChanged", QUEUE_SIZE, &Drone::positionChanged, this);
    altitudeSub = pNodeHandle->subscribe(name + "/states/ardrone3/PilotingState/AltitudeChanged", QUEUE_SIZE, &Drone::altitudeChanged, this);
    attitudeSub = pNodeHandle->subscribe(name + "/states/ardrone3/PilotingState/AttitudeChanged", QUEUE_SIZE, &Drone::attitudeChanged, this);
    flyingStateSub = pNodeHandle->subscribe(name + "/states/ardrone3/PilotingState/FlyingStateChanged", QUEUE_SIZE, &Drone::flyingStateChanged, this);
    odometrySub = pNodeHandle->subscribe(name + "/odom", QUEUE_SIZE, &Drone::odometryChanged, this);

    takeoff_pub = pNodeHandle->advertise<std_msgs::Empty>(name + "/takeoff", QUEUE_SIZE);
    land_pub = pNodeHandle->advertise<std_msgs::Empty>(name + "/land", QUEUE_SIZE);
    reset_pub = pNodeHandle->advertise<std_msgs::Empty>(name + "/reset", QUEUE_SIZE);
    cmd_vel_pub = pNodeHandle->advertise<geometry_msgs::Twist>(name + "/cmd_vel", QUEUE_SIZE);

    flyingState = 0;
    bearing = 0.0;
}

void Drone::debugGlobalPosition() {
    printf("Drone global position \n");
    printf("Global Position \n");
    printf("  latitude  : %0.12f \n", globalPosition.latitude);
    printf("  longitude : %0.12f \n", globalPosition.longitude);
    printf("  altitude  : %0.12f \n", globalPosition.altitude);
    printf("-------------------------- \n");
}

void Drone::debugDescription() {
    printf("Drone description \n");
    printf("CalculatedCartesianCoordinate \n");
    printf("  x: %0.12f \n", odometry.x);
    printf("  y: %0.12f \n", odometry.y);
    printf("  z: %0.12f \n", odometry.z);
    printf("------------ \n");
}

bool Drone::isReady() {
    if (globalPosition.isReady() && odometry.isReady()) return true;
    
    return false;
}

uint8_t Drone::getFlyingState() {
    return flyingState;
}

std::string Drone::getName() {
    return name;
}

float Drone::getBearing() {
    return bearing;
}

GlobalPosition Drone::getGlobalPosition() {
    return globalPosition;
}

double Drone::getLatitude() {
    return globalPosition.latitude;
}

double Drone::getLongitude() {
    return globalPosition.longitude;
}

double Drone::getAltitude() {
    return globalPosition.altitude;
}

double Drone::getMatchingX() {
    return odometryMatchingGlobalPosition.x;
}

double Drone::getMatchingY() {
    return odometryMatchingGlobalPosition.y;
}

double Drone::getMatchingZ() {
    return odometryMatchingGlobalPosition.z;
}

double Drone::getOdometryX() {
    return odometry.x;
}

double Drone::getOdometryY() {
    return odometry.y;
}

double Drone::getOdometryZ() {
    return odometry.z;
}

void Drone::setMission(Mission* pMission) {
    this->pMission = pMission;

    callWhenPositionChanged = pMission->getCallWhenPositionChanged();
    callWhenAltitudeChanged = pMission->getCallWhenAltitudeChanged();
    callWhenBearingChanged = pMission->getCallWhenBearingChanged();
}





// subscribe
void Drone::positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg) {
    globalPosition.latitude = msg->latitude;
    globalPosition.longitude = msg->longitude;

    odometryMatchingGlobalPosition.x = odometry.x;
    odometryMatchingGlobalPosition.y = odometry.y;
    odometryMatchingGlobalPositionOrientationZ = odometryOrientationZ;

    if (callWhenPositionChanged) callWhenPositionChanged(pMission, *this);
}

void Drone::altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg) {
    globalPosition.altitude = msg->altitude;

    odometryMatchingGlobalPosition.z = odometry.z;

    if (callWhenAltitudeChanged) callWhenAltitudeChanged(pMission, *this);
}

void Drone::attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg) {
    bearing = msg->yaw;    // msg->yaw is magnetic bearing_rad

    if (callWhenBearingChanged) callWhenBearingChanged(pMission, *this);

    debugTestDescription();
}

void Drone::flyingStateChanged(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::ConstPtr& msg) {
    flyingState = msg->state;
}

void Drone::odometryChanged(const nav_msgs::Odometry::ConstPtr& msg) {
    odometry.x = msg->pose.pose.position.x;
    odometry.y = msg->pose.pose.position.y;
    odometry.z = msg->pose.pose.position.z;
    odometryOrientationZ = msg->pose.pose.orientation.z;    // -1 ~ 1

    debugTestDescription();
}

void Drone::debugTestDescription() {
    // printf("Bearing: %0.12f \n", bearing);
    // printf("Bearing(angle): %0.12f \n", bearing / M_PI * 180);
    // printf("OdometryOrientationZ: %0.12f \n", odometryOrientationZ);
    // printf("---------------------------------- \n");
}





// publish
void Drone::takeoff() {
    takeoff_pub.publish(emptyMsg);
}

void Drone::land() {
    land_pub.publish(emptyMsg);
}

void Drone::reset() {
    reset_pub.publish(emptyMsg);
}

void Drone::fly(double x, double y, double z, double yaw) {
    twistMsg.linear.x = x;
    twistMsg.linear.y = y;
    twistMsg.linear.z = z;
    twistMsg.angular.z = yaw;

    cmd_vel_pub.publish(twistMsg);
}
