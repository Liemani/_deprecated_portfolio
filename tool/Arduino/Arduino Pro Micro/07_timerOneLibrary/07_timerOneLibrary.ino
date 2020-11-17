#include <TimerOne.h>

const int MOTOR_FL = 6;
const int MOTOR_FR = 10;
const int MOTOR_BL = 5;
const int MOTOR_BR = 9;

const int MOTOR_ARRAY[4] = {MOTOR_FL, MOTOR_FR, MOTOR_BL, MOTOR_BR};

const int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {
    Timer1.initialize();

    Timer1.setPeriod(1000000 / 262);
    
    for (int i = 0; i < 4; ++i) {
        Timer1.pwm(MOTOR_ARRAY[i], 7);    // volume, if too big, motor run
    }

    for (int i = 0; i < 7; ++i) {
        Timer1.setPeriod(1000000 / melody[i]);
        delay(500);
    }

    for (int i = 7; i >= 0; --i) {
        Timer1.setPeriod(1000000 / melody[i]);
        delay(500);
    }
}

void loop() {
}
