// the sound is not good as i expected
// retry by modifying the time of delay!!

// preprocessor
#define MOTOR_PIN_FL 6
#define MOTOR_PIN_FR 10
#define MOTOR_PIN_BL 5
#define MOTOR_PIN_BR 9



// variable
const int MOTOR_ARRAY[] = {MOTOR_PIN_FL, MOTOR_PIN_FR, MOTOR_PIN_BL, MOTOR_PIN_BR};

const int MELODY[] = {262, 294, 330, 349, 392, 440, 494, 523};    // hertz

int count;
int hertz;
int interval;

int long previousTime;    // unit: micro second
int long currentTime;    // unit: micro second

int dutyCycle;



// main function
void setup() {
    for (int i = 0; i < 4; ++i) {
        pinMode(MOTOR_ARRAY[i], OUTPUT);
    }

    count = 0;
    hertz = MELODY[count];
    interval = 1000000 / hertz;
    
    previousTime = micros();
}

void loop() {
    currentTime = micros();
    
    if (currentTime - previousTime > 1000000) {
        if (count < 7) {
            ++count;
            hertz = MELODY[count];
            interval = 1000000 / hertz;
        }
        
        previousTime = currentTime;
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
