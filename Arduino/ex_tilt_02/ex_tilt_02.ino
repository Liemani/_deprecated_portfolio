#define led 13
#define pinGnd 4
#define pinVcc 3
#define pinTilt 2

void setup() {
    Serial.begin(115200);

    pinMode(led, OUTPUT);
    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinTilt, INPUT);

    digitalWrite(led, LOW);
    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);
}

void loop() {
    if (!digitalRead(pinTilt)) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }

    delay(500);
}
