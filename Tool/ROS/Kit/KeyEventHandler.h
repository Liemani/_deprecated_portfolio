#ifndef KEYEVENTCONTROLLER_H
#define KEYEVENTCONTROLLER_H





typedef void (*SimpleFunction)();

class KeyEventHandler {
private:
    static int* pPressedKey;

    static void handleKeyEvent();

public:
    static SimpleFunction getHandleKeyEvent(int* pPressedKey);

};

#endif
