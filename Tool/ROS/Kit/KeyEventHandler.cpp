#include <stdio.h>    // getchar()
#include <termio.h>

#include "KeyEventHandler.h"





int* KeyEventHandler::pPressedKey = NULL;    // you must init the class member variable!!

static int getch() {
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

void KeyEventHandler::getPressedKey() {
    while(true)
        *pPressedKey = getch();
}

SimpleFunction KeyEventHandler::generateFunction(int* pPressedKey) {
    KeyEventHandler::pPressedKey = pPressedKey;
    return getPressedKey;
}
