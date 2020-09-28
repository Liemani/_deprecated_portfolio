#include <thread>

#include <KeyEventHandler.h>

#include "CustomMissionHandler.h"

using std::thread;





int main(int argc, char** argv) {
    CustomMissionHandler missionHandler(argc, argv);

    thread keyEventHandleThread = thread(KeyEventHandler::getHandleKeyEvent(missionHandler.getPCommand()));

    missionHandler.loop();

    return 0;
}
