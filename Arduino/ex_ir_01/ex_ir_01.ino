//********************************************
// char* title = "ex_ir_01"
// made by Lieman at 2020.06.12
//
// description:
//  IR example
//********************************************





#define RECV_PIN 13
#define VCC_PIN 12
#define GND_PIN1 11

#define GND_PIN2 5
#define TRANS_PIN 3

void setup() {
    Serial.begin(115200);
    
    pinMode(RECV_PIN, INPUT);
    pinMode(VCC_PIN, OUTPUT);
    pinMode(GND_PIN1, OUTPUT);
    
    pinMode(GND_PIN2, OUTPUT);
    pinMode(TRANS_PIN, OUTPUT);

    digitalWrite(VCC_PIN, HIGH);
    digitalWrite(GND_PIN1, LOW);
    
    digitalWrite(GND_PIN2, LOW);
    digitalWrite(TRANS_PIN, LOW);
}

void loop() {
    if (Serial.available() > 0) {
        Serial.read();
        digitalWrite(TRANS_PIN, !digitalRead(TRANS_PIN));
    }

    Serial.print("ir emission: ");
    Serial.println(digitalRead(TRANS_PIN) ? "ON" : "OFF");
    
    if (digitalRead(RECV_PIN)) {
        Serial.println("Signal No");
    } else {
        Serial.println("Signal On");
    }
    Serial.print('\n');

    delay(100);
}
