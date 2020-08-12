// the sound is not good as i expected
// retry by modifying the time of delay!!

// preprocessor
#define MOTOR_PIN_FL = 6;
#define MOTOR_PIN_FR = 10;
#define MOTOR_PIN_BL = 5;
#define MOTOR_PIN_BR = 9;



// variable
const int MOTOR_ARRAY[4] = {MOTOR_PIN_FL, MOTOR_PIN_FR, MOTOR_PIN_BL, MOTOR_PIN_BR};

const int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};    // hertz

int count;
int hertz;
int interval;

int long previousTime;    // unit: micro second

int dutyCycle;



// main function
void setup() {
    for (int i = 0; i < 4; ++i) {
        pinMode(MOTOR_ARRAY[i], OUTPUT);
    }

    count = 0;
    hertz = melody[count];
    interval = 1000000 / hertz;
    
    previousMicroSeconds = micros();
}

void loop() {
    if (micros() - previousMicroSeconds > 1000000) {
        if (count < 7) {
            ++count;
            hertz = melody[count];
            interval = 1000000 / hertz;
        }
        
        previousMicroSeconds = micros();
    }
    
    for (int i = 0; i < 4; ++i) {
        digitalWrite(MOTOR_ARRAY[i], HIGH);
    }

    dutyCycle = interval / 100;
    delayMicroseconds(dutyCycle);

    for (int i = 0; i <4; ++i) {
        digitalWrite(MOTOR_ARRAY[i], LOW);
    }
    
    delayMicroseconds(interval - dutyCycle);
}
