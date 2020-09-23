#ifndef KEYEVENTCONTROLLER_H
#define KEYEVENTCONTROLLER_H





typedef void (*SimpleFunction)();

class KeyEventHandler {
private:
    static int* pPressedKey;

    static void getPressedKey();

public:
    static SimpleFunction generateFunction(int* pPressedKey);

};

#endif
