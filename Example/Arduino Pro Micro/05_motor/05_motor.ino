const int MOTOR_FL = 6;
const int MOTOR_FR = 10;
const int MOTOR_BL = 5;
const int MOTOR_BR = 9;

const int MOTOR_ARRAY[4] = {MOTOR_FL, MOTOR_FR, MOTOR_BL, MOTOR_BR};

void setup() {
    pinMode(MOTOR_FL, OUTPUT);
    pinMode(MOTOR_FR, OUTPUT);
    pinMode(MOTOR_BL, OUTPUT);
    pinMode(MOTOR_BR, OUTPUT);
}

void loop() {
    for (int i = 0; i < 4; ++i) {
        digitalWrite(MOTOR_ARRAY[i], HIGH);
    }

    delayMicroseconds(2000);
    
    for (int i = 0; i < 4; ++i) {
        digitalWrite(MOTOR_ARRAY[i], LOW);
    }
    
    delayMicroseconds(8000);
}
