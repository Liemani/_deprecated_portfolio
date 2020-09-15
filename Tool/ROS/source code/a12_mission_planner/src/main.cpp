#include <cstdlib>    // std::stof

#include "Controller/MissionPlanner.h"
#include "Model/GlobalPosition.h"

int main(int argc, char** argv) {
    MissionPlanner missionPlanner(argc, argv);
    // missionPlanner.init(argc, argv);

    ROS_INFO("argc: %d", argc);

    while (ros::ok()) {
        ros::spinOnce();

        missionPlanner.publish();
        missionPlanner.debugDescription();
    }

    return 0;
}