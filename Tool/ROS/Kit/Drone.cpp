#include "Drone.h"

#define QUEUE_SIZE 1

using std::string;





Drone::Drone(MissionPlanner* pPlanner,
        ros::NodeHandle* pNodeHandle,
        std::string ncurrentCalculatedPositioname = "bebop") {
    this->name = name;

    this->pPlanner = pPlanner;
    this->callWhenPositionChanged = callWhenPositionChanged;

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





uint8_t Drone::getFlyingState() {
    return flyingState;
}

std::string Drone::getName() {
    return name;
}

float Drone::getBearing() {
    return bearing;
}

GlobalPosition getGlobalPosition() {
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
    return matchingCalculatedPosition.x;
}

double Drone::getMatchingY() {
    return matchingCalculatedPosition.y;
}

double Drone::getMatchingZ() {
    return matchingCalculatedPosition.z;
}

double Drone::getCalculatedX() {
    return calculatedCurrentPosition.x;
}

double Drone::getCalculatedY() {
    return calculatedCurrentPosition.y;
}

double Drone::getCalculatedZ() {
    return calculatedCurrentPosition.z;
}





// subscribe
void Drone::positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg) {
    globalPosition.latitude = msg->latitude;
    globalPosition.longitude = msg->longitude;

    matchingCalculatedPosition = calculatedCurrentPosition;

    if (callWhenPositionChanged) callWhenPositionChanged(*pPlanner, *this);
}

void Drone::altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg) {
    globalPosition.altitude = msg->altitude;
}

void Drone::attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg) {
    bearing = msg->yaw;    // msg->yaw is magnetic bearing_rad
}

void Drone::flyingStateChanged(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::ConstPtr& msg) {
    flyingState = msg->state;
}

void Drone::odometryChanged(const nav_msgs::Odometry::ConstPtr& msg) {
    calculatedCurrentPosition.x = msg->pose.pose.position.x;
    calculatedCurrentPosition.y = msg->pose.pose.position.y;
    calculatedCurrentPosition.z = msg->pose.pose.position.z;
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
