#include <thread>

#include <KeyEventHandler.h>

#include "CustomMissionHandler.h"

using std::thread;





int pressedKey;

int main(int argc, char** argv) {
    thread keyEventHandleThread = thread(KeyEventHandler::generateFunction(&pressedKey));

    CustomMissionHandler missionHandler(argc, argv, &pressedKey);
    missionHandler.loop();

    return 0;
}
