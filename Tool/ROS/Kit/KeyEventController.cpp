#include <termio.h>

#include "KeyEventController.h"

using std::thread;





int* KeyEventController::pPressedKey = NULL;

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

void KeyEventController::getPressedKey() {
    while(true)
        *pPressedKey = getch();
}

thread* KeyEventController::makeKeyEventThread(int* pPressedKey) {
    KeyEventController::pPressedKey = pPressedKey;
    return new thread(getPressedKey);
}
