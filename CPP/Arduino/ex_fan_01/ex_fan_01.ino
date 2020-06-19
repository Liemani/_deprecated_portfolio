//********************************************
// char* title = "ex_fan_01"
// made by Lieman at 2020.06.12
//
// description:
//  fan example
//********************************************





#define FAN_PIN 13

uint8_t ch;

void setup() {
    Serial.begin(115200);

    pinMode(FAN_PIN, OUTPUT);
    digitalWrite(FAN_PIN, LOW);
}

void loop() {
    if (Serial.available() > 0) {
        ch = Serial.read();

        if (ch == 'O') {
            digitalWrite(FAN_PIN, HIGH);
        } else if (ch == 'X') {
            digitalWrite(FAN_PIN, LOW);
        }
    }
}
