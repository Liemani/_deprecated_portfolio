********************************************
// char* title = "ex_motor_01"
// made by Lieman at 2020.06.12
//
// description:
//  motor example
//********************************************





// global constatant#define POS_PIN 5
#define NEG_PIN 4
#define ENA_PIN 3

#define SPEED 250
#define DURATION 1000

uint8_t ch;

void setup() {
    Serial.begin(115200);

    pinMode(POS_PIN, OUTPUT);
    pinMode(NEG_PIN, OUTPUT);
    pinMode(ENA_PIN, OUTPUT);
    
    digitalWrite(POS_PIN, LOW);
    digitalWrite(NEG_PIN, LOW);
    digitalWrite(ENA_PIN, LOW);
}

void loop() {
    if (Serial.available() > 0) {
        ch = Serial.read();

        if (ch == 'p') {
            clockWise(SPEED);
        } else if (ch == 'n') {
            counterClockWise(SPEED);
        } else if (ch == 's') {
            motorStop();
        }
    }
}

void clockWise(int speed) {
    digitalWrite(POS_PIN, HIGH);
    digitalWrite(NEG_PIN, LOW);
    analogWrite(ENA_PIN, speed);
}

void counterClockWise(int speed) {
    digitalWrite(POS_PIN, LOW);
    digitalWrite(NEG_PIN, HIGH);
    analogWrite(ENA_PIN, speed);
}

void motorStop() {
    digitalWrite(ENA_PIN, LOW);
    digitalWrite(POS_PIN, LOW);
    digitalWrite(NEG_PIN, LOW);
}
