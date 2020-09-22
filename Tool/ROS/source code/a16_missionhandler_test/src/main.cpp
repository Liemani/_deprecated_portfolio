#include <thread>

#include <KeyEventController.h>

#include "CustomMissionHandler.h"

using std::thread;




int pressedKey;

int main(int argc, char** argv) {
    thread* keyEventThread = KeyEventController::makeKeyEventThread(&pressedKey);

    CustomMissionHandler missionHandler(argc, argv, &pressedKey);
    missionHandler.loop();

    return 0;
}
