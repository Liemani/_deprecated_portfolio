#include <string>

#include <Drone.h>

#include "CustomMissionHandler.h"

using std::string;





void CustomMissionHandler::processCommand() {
    // action code for command goes here...
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv)
: MissionHandler(argc, argv, "a21_mission_tester") {
    // initializing drone code here...
}
