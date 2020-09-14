#include "Controller/MissionPlanner.h"

int main(int argc, char** argv) {
    MissionPlanner missionPlanner(argc, argv);
    // missionPlanner.init(argc, argv);

    ROS_INFO("argc: %d", argc);

    if (argc == 1) {
        while (ros::ok()) {
            ros::spinOnce();

            missionPlanner.publish();
            missionPlanner.debugDescription();
        }
    } else if (argc == 4) {
        missionPlanner.moveToTargetPosition(targetPosition);
    }

    return 0;
}