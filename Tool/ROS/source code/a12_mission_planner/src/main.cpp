#include <string>

#include "Controller/MissionPlanner.h"
#include "Model/MissionPlannerState.h"

using std::string;
using std::stod;

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
        missionPlanner.targetPositionVector.push_back(GlobalPosition(stod(string(argv[1])), stod(string(argv[2])), stod(string(argv[3]))));
        missionPlanner.moveToTargetPosition();
    }

    return 0;
}