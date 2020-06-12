********************************************
// char* title = "ex_ultrasonic_01"
// made by Lieman at 2020.06.12
//
// description:
//  ultrasonic example
//********************************************





#define TRIGGER_PIN 13
#define ECHO_PIN 12

#define ULTRASONICSPEEDPERMS 340
#define DISTANCE_LIMIT 4000

uint8_t ch;

unsigned long startTime = 0;
unsigned long distance;

void setup() {
    Serial.begin(115200);
    
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    digitalWrite(TRIGGER_PIN, LOW);
}

void loop() {
    if (Serial.available() > 0) {
        Serial.read();
        digitalWrite(TRIGGER_PIN, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIGGER_PIN, LOW);
    }
    
    if (startTime == 0 && digitalRead(ECHO_PIN) == HIGH) {
        startTime = micros();
    }

    if (startTime != 0 && digitalRead(ECHO_PIN) == LOW) {
        distance = (micros() - startTime) * ULTRASONICSPEEDPERMS / 1000 / 2;
        
        if (distance > DISTANCE_LIMIT) {
            Serial.println("Too far!");
        } else {
            Serial.print(distance);
            Serial.println("mm");
        }
        
        startTime = 0;
    }
}
