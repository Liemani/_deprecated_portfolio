// the sound is not good as i expected
// retry by modifying the time of delay!!

const int MOTOR_FL = 6;
const int MOTOR_FR = 10;
const int MOTOR_BL = 5;
const int MOTOR_BR = 9;

const int MOTOR_ARRAY[4] = {MOTOR_FL, MOTOR_FR, MOTOR_BL, MOTOR_BR};

const int melody[] = {262, 294, 330, 349, 392, 440, 494, 523};

int long previousMicroSeconds;
int count;
int hertzSupplement;

void setup() {
    Serial.begin(115200);
    
    for (int i = 0; i < 4; ++i) {
        pinMode(MOTOR_ARRAY[i], OUTPUT);
    }

    previousMicroSeconds = micros();
    count = 0;
    hertzSupplement = melody[count];
}

void loop() {
    Serial.println(count);
    
    Serial.print("micors(): ");
    Serial.println(micros());
    Serial.print("prev: ");
    Serial.println(previousMicroSeconds);
    
    if (micros() - previousMicroSeconds > 1000000) {
        previousMicroSeconds = micros();

        if (count < 7) {
            ++count;
            hertzSupplement =  10000 / melody[count];
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        digitalWrite(MOTOR_ARRAY[i], HIGH);
    }
    
    delayMicroseconds(1 * hertzSupplement);

    for (int i = 0; i <4; ++i) {
        digitalWrite(MOTOR_ARRAY[i], LOW);
    }
    
    delayMicroseconds(99 * hertzSupplement);
}
