#ifndef MISSIONPLANNER_H
#define MISSIONPLANNER_H

#include <ros/ros.h>
#include <stdio.h>    // getchar()
#include <math.h>

#include <termio.h>    // struct termios

#include "../Model/GlobalPosition.h"
#include "../Model/Drone.h"

using std::vector;

class MissionPlanner {
private:
    std::vector<Drone> droneVector;

    ros::NodeHandle* nh;

    int missionState;

    int input_data;

    GlobalPosition savedPosition;
    
    // mission variable
    double latitudeA_rad;
    double longitudeA_rad;

    double latitudeB_rad;
    double longitudeB_rad;

    double deltaLatitude_rad;
    double deltaLongitude_rad;



    double a;
    double distance;



    double X;
    double Y;

    double directionAngle;

public:
    MissionPlanner(int argc, char** argv, std::string name = "bebop");

    void moveToTargetPosition();

    void publish();
    void debugDescription();
};

#endif