const int MOTOR_FL = 6;
const int MOTOR_FR = 10;
const int MOTOR_BL = 5;
const int MOTOR_BR = 9;

const int MOTOR_ARRAY[4] = {MOTOR_FL, MOTOR_FR, MOTOR_BL, MOTOR_BR};

void setup() {
    for (int i = 0; i < 4; ++i) {
        analogWrite(MOTOR_ARRAY[i], 25);
    }
}

void loop() {
}
