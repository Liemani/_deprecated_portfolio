#ifndef KEYEVENTCONTROLLER_H
#define KEYEVENTCONTROLLER_H

#include <thread>





class KeyEventController {
private:
    static int* pPressedKey;

    static void getPressedKey();

public:
    static std::thread* makeKeyEventThread(int* pressedKey);

};

#endif
