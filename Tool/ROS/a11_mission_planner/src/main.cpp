#include "MissionPlanner.h"

int main(int argc, char** argv) {
    MissionPlanner missionPlanner(argc, argv);
    // missionPlanner.init(argc, argv);

    while (1) {
        missionPlanner.publish();
    }

    return 0;
}