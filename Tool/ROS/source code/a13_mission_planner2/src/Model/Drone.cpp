#include "Drone.h"

#define QUEUE_SIZE 1

using std::string





Drone::Drone(string name, ros::NodeHandle* nodeHandle) {
    this->name = name;

    positionSub = nh->subscribe(name + "/states/ardrone3/PilotingState/PositionChanged", QUEUE_SIZE, &Drone::positionChanged, this);
    altitudeSub = nh->subscribe(name + "/states/ardrone3/PilotingState/AltitudeChanged", QUEUE_SIZE, &Drone::altitudeChanged, this);
    attitudeSub = nh->subscribe(name + "/states/ardrone3/PilotingState/AttitudeChanged", QUEUE_SIZE, &Drone::attitudeChanged, this);
    flyingStateSub = nh->subscribe(name + "/states/ardrone3/PilotingState/FlyingStateChanged", QUEUE_SIZE, &Drone::flyingStateChanged, this);
    odometrySub = nh->subscribe(name + "/odom", QUEUE_SIZE, &Drone::odometryChanged, this);

    takeoff_pub = nh->advertise<std_msgs::Empty>(name + "/takeoff", QUEUE_SIZE);
    land_pub = nh->advertise<std_msgs::Empty>(name + "/land", QUEUE_SIZE);
    reset_pub = nh->advertise<std_msgs::Empty>(name + "/reset", QUEUE_SIZE);
    cmd_vel_pub = nh->advertise<geometry_msgs::Twist>(name + "/cmd_vel", QUEUE_SIZE);
}





// subscribe
void Drone::positionChanged(const bebop_msgs::Ardrone3PilotingStatePositionChanged::ConstPtr& msg) {
    currentGlobalPosition.latitude = msg->latitude;
    currentGlobalPosition.longitude = msg->longitude;
}

void Drone::altitudeChanged(const bebop_msgs::Ardrone3PilotingStateAltitudeChanged::ConstPtr& msg) {
    currentGlobalPosition.altitude = msg->altitude;
}

void Drone::attitudeChanged(const bebop_msgs::Ardrone3PilotingStateAttitudeChanged::ConstPtr& msg) {
    bearing_rad = msg->yaw;    // msg->yaw is magnetic bearing_rad
}

void Drone::flyingStateChanged(const bebop_msgs::Ardrone3PilotingStateFlyingStateChanged::ConstPtr& msg) {
    flyingState = msg->state;
}

void Drone::odometryChanged(const nav_msgs::Odometry::ConstPtr& msg) {
    currentCalculatedPosition.x = msg->pose.position.x;
    currentCalculatedPosition.y = msg->pose.position.y;
    currentCalculatedPosition.z = msg->pose.position.z;
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
