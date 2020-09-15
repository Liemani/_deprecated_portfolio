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





int getch() {
    int ch;

    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);

    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();

    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}





MissionPlanner::MissionPlanner(int argc, char** argv) {
    ros::init(argc, argv, "a13_mission_planner_node2");    // node name
    nh = new ros::NodeHandle();

    missionState = state_noMission;

    droneVector.push_back(Drone("bebop", nh));
}

void MissionPlanner::moveToTargetPosition() {
    latitudeA_rad = droneVector[i]->currentPosition.latitude / 180 * PI;
    longitudeA_rad = droneVector[i]->currentPosition.longitude / 180 * PI;

    latitudeB_rad = savedPosition.latitude / 180 * PI;
    longitudeB_rad = savedPosition.longitude / 180 * PI;

    deltaLatitude_rad = latitudeB_rad - latitudeA_rad;
    deltaLongitude_rad = longitudeB_rad - longitudeA_rad;



    a = pow(sin(deltaLatitude_rad / 2), 2) + cos(latitudeA_rad) * cos(latitudeB_rad) * pow(sin(deltaLongitude_rad / 2), 2);
    distance = RADIUS_OF_EARTH * (2 * atan2(sqrt(a), sqrt(1 - a))) * 1000;



    X = cos(latitudeB_rad) * sin(deltaLongitude_rad);
    Y = cos(latitudeA_rad) * sin(latitudeB_rad) - sin(latitudeA_rad) * cos(latitudeB_rad) * cos(deltaLongitude_rad);

    directionAngle = droneVector[i]->bearing - atan2(X, Y);



    if (distance > 5) {
        droneVector[i]->fly(RATIO * cos(directionAngle), (savedPosition.altitude - currentPosition.altitude) / distance * RATIO, 0);
    } else if (distance > 0.05) {
        droneVector[i]->fly(SLOW_RATIO * cos(directionAngle), SLOW_RATIO * sin(directionAngle, (savedPosition.altitude - currentPosition.altitude) / distance * SLOW_RATIO, 0);
    } else {
        missionState = state_noMission;
    }
}

void MissionPlanner::publish() {
    input_data = getch();

    for (int i = 0; i < droneVector.size(); ++i) {
        if (missionState == state_noMission) {
            switch(input_data) {
                case 116:    // takeoff
                    if (droneVector[i]->flyingState == state_landed)
                        droneVector[i]->takeoff();
                    break;
                case 98:    // land
                    if (droneVector[i]->flyingState == state_hovering)
                        droneVector[i]->land();
                    break;
                case 103:    // reset
                    droneVector[i]->reset();
                    break;
                case 119:    // forward
                    droneVector[i]->fly(RATIO, 0, 0, 0);
                    break;
                case 115    // backward
                    droneVector[i]->fly(-RATIO, 0, 0, 0);
                    break;
                case 97    // leftward
                    droneVector[i]->fly(0, RATIO, 0, 0);
                    break;
                case 100    // rightward
                    droneVector[i]->fly(0, -RATIO, 0, 0);
                    break;
                case 105    // upward
                    droneVector[i]->fly(0, 0, RATIO, 0);
                    break;
                case 107    // downward
                    droneVector[i]->fly(0, 0, -RATIO, 0);
                    break;
                case 106    // turn left
                    droneVector[i]->fly(0, 0, 0, RATIO);
                    break;
                case 108    // turn right
                    droneVector[i]->fly(0, 0, 0, -RATIO);
                    break;
                case 113    // hovering
                    droneVector[i]->fly(0, 0, 0, 0);
                    break;
                case 122    // save current position to savedPosition
                    savedPosition.latitude = droneVector[i]->currentPosition.latitude;
                    savedPosition.longitude = droneVector[i]->currentPosition.longitude;
                    savedPosition.altitude = droneVector[i]->currentPosition.altitude;
                    break;
                case 120    // move to savedPosition
                    missionState = state_onMission;
                    break;
                default:
                    break;
            }
        } else if (missionState == state_onMission) {
            moveToTargetPosition();
        }
    }
}

void MissionPlanner::debugDescription() {
    for (int i = 0; i < droneVector.size(); ++i) {
        printf("Name: %s", droneVector[i].name.c_str());
        printf("Latitude: %.15f \n", droneVector[i]->currentPosition.latitude);
        printf("Longitude: %.15f \n", droneVector[i]->currentPosition.longitude);
        printf("Altitude: %.15f \n", droneVector[i]->currentPosition.altitude);
        printf("\n");
        printf("Yaw: %.15f \n", droneVector[i]->bearing);
        printf("\n");
        printf("Flying state: %d \n", droneVector[i]->flyingState);
        printf("---------------- \n");
    }
}
