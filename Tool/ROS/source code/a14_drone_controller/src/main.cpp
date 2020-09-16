#include <stdio.h>
#include <thread>
#include <termio.h>    // struct termios

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





int pressedKey;





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
    std::thread first(getPressedKey);

    ros::init(argc, argv, "a14_drone_controller_node");
    ros::NodeHandle pNodeHandle;

    Drone* pDrone;

    if (argc == 1) {
        pDrone = new Drone(&pNodeHandle);
    } else if (argc == 2) {
        pDrone = new Drone(&pNodeHandle, argv[1]);
    }

    while (ros::ok()) {
        ros::spinOnce();

        switch(pressedKey) {
            case 116:    // takeoff
                if (pDrone->getFlyingState() == state_landed)
                    pDrone->takeoff();

                pressedKey = 0;
                break;
            case 98:    // land
                if (pDrone->getFlyingState() == state_hovering)
                    pDrone->land();

                pressedKey = 0;
                break;
            case 103:    // reset
                pDrone->reset();

                pressedKey = 0;
                break;
            case 119:    // forward
                pDrone->fly(RATIO, 0, 0, 0);

                pressedKey = 0;
                break;
            case 115:    // backward
                pDrone->fly(-RATIO, 0, 0, 0);

                pressedKey = 0;
                break;
            case 97:    // leftward
                pDrone->fly(0, RATIO, 0, 0);

                pressedKey = 0;
                break;
            case 100:    // rightward
                pDrone->fly(0, -RATIO, 0, 0);

                pressedKey = 0;
                break;
            case 105:    // upward
                pDrone->fly(0, 0, RATIO, 0);

                pressedKey = 0;
                break;
            case 107:    // downward
                pDrone->fly(0, 0, -RATIO, 0);

                pressedKey = 0;
                break;
            case 106:    // turn left
                pDrone->fly(0, 0, 0, RATIO);

                pressedKey = 0;
                break;
            case 108:    // turn right
                pDrone->fly(0, 0, 0, -RATIO);

                pressedKey = 0;
                break;
            case 113:    // hovering
                pDrone->fly(0, 0, 0, 0);

                pressedKey = 0;
                break;
            case 99:    // debug description
                debugDescription(pDrone);

                pressedKey = 0;
                break;
            default:
                break;
        }
    }

    return 0;
}