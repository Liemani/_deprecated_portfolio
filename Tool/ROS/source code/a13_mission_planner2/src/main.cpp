#include <stdio.h>    // for debuggin prinf()
#include <thread>
#include <termio.h>    // struct termios

#include <Controller/MissionPlanner.h>





using std::thread;





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

int main(int argc, char** argv) {
    thread getPressedKey_thread = thread(getPressedKey);

    ros::init(argc, argv, "a13_mission_planner_node");
    ros::NodeHandle nh = ros::NodeHandle();

    MissionPlanner missionPlanner = MissionPlanner(argc, argv, &nh);

    while (ros::ok()) {
        ros::spinOnce();

        if (missionPlanner.processCommand(pressedKey)) pressedKey = 0;
        missionPlanner.doMission();
        // missionPlanner.debugDescription();
    }

    return 0;
}
