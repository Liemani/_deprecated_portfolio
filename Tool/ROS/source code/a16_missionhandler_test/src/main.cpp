#include <thread>

#include <KeyEventHandler.h>

#include "CustomMissionHandler.h"

using std::thread;





int main(int argc, char** argv) {
    int pressedKey;

    thread keyEventHandleThread = thread(KeyEventHandler::getHandleKeyEvent(&pressedKey));

    CustomMissionHandler missionHandler(argc, argv, &pressedKey);

    missionHandler.loop();

    return 0;
}
