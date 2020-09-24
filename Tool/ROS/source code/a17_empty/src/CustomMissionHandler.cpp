#include <string>

#include <Drone.h>

#include "CustomMissionHandler.h"
#include "Mission/CustomMission.h"

using std::string;





void CustomMissionHandler::processCommand() {
    // action code for command goes here...
}





// public
CustomMissionHandler::CustomMissionHandler(int argc, char** argv, int* pCommand)
: MissionHandler(argc, argv, "a17_empty_node", pCommand) {
    // initializing drone code here...
}
