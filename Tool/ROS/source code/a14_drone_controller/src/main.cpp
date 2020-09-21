#include <stdio.h>
#include <thread>
#include <termio.h>    // struct termios
#include <map>

#include <Model/Drone.h>

#define state_landed 0
#define state_takingOff 1
#define state_hovering 2
#define state_flying 3
#define state_landing 4
#define state_emergency 5
#define state_userTakeOff 6
#define state_motorRamping 7
#define state_emergencyLanding 8

#define RATIO 0.5

using std::map;
using std::thread;





int pressedKey;

typedef void (*CommandProcessor)(Drone& drone, double ratio);

map<int, CommandProcessor> commandMap = {
    {48,
        [](Drone& drone, double ratio) {    // takeoff
            if (drone.getFlyingState() == state_landed)
                drone.takeoff();
        }
    },
    {10,
        [](Drone& drone, double ratio) {    // land
            if (drone.getFlyingState() == state_hovering)
                drone.land();
        }
    },
    { 46, [](Drone& drone, double ratio){ drone.reset(); } },

    { 49, [](Drone& drone, double ratio){ drone.flyBackwardLeftward(ratio); } },
    { 50, [](Drone& drone, double ratio){ drone.flyBackward(ratio); } },
    { 51, [](Drone& drone, double ratio){ drone.flyBackwardRightward(ratio); } },
    { 52, [](Drone& drone, double ratio){ drone.flyLeftward(ratio); } },
    { 53, [](Drone& drone, double ratio){ drone.hover(); } },
    { 54, [](Drone& drone, double ratio){ drone.flyRightward(ratio); } },
    { 55, [](Drone& drone, double ratio){ drone.flyForwardLeftward(ratio); } },
    { 56, [](Drone& drone, double ratio){ drone.flyForward(ratio); } },
    { 57, [](Drone& drone, double ratio){ drone.flyForwardRightward(ratio); } },

    { 45, [](Drone& drone, double ratio){ drone.flyUpward(ratio); } },
    { 43, [](Drone& drone, double ratio){ drone.flyDownward(ratio); } },

    { 47, [](Drone& drone, double ratio){ drone.flyTurnLefft(ratio); } },
    { 42, [](Drone& drone, double ratio){ drone.flyTurnRight(ratio); } },
};





int getch() {
    int ch;

    struct termios buf, save;
    tcgetattr(0, &save);
    buf = save;

    buf.c_lflag &= ~(ICANON|ECHO);

    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;

    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();

    tcsetattr(0, TCSAFLUSH, &save);

    return ch;
}

void getPressedKey() {
    while(true) {
        pressedKey = getch();
    }
}

void debugDescription(Drone* drone) {
    printf("Flying state: %d \n", drone->getFlyingState());
}

int main(int argc, char** argv) {
    thread first(getPressedKey);

    ros::init(argc, argv, "a14_drone_controller_node");
    ros::NodeHandle pNodeHandle;

    Drone* pDrone;

    if (argc == 1) {    // use default name 'bebop'
        pDrone = new Drone(&pNodeHandle);
    } else if (argc == 2) {    // use custom input name "argv[1]"
        pDrone = new Drone(&pNodeHandle, argv[1]);
    }

    while (ros::ok()) {
        ros::spinOnce();
        if (pressedKey == 0) continue;

        static CommandProcessor commandProcessor;
        if (commandProcessor = commandMap[pressedKey]) {
            commandProcessor(*pDrone, RATIO);
            pressedKey = 0;
        }
    }

    return 0;
}