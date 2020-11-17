//********************************************
// char* title = "ex_joystick_01"
// made by Lieman at 2020.06.12
//
// description:
//  joystick example
//********************************************





#define GND_PIN A0
#define VCC_PIN A1
#define VRX_PIN A2
#define VRY_PIN A3
#define SW_PIN A4

void setup() {
    Serial.begin(115200);
    
    pinMode(GND_PIN, OUTPUT);
    pinMode(VCC_PIN, OUTPUT);
    pinMode(VRX_PIN, INPUT);
    pinMode(VRY_PIN, INPUT);
    pinMode(SW_PIN, INPUT_PULLUP);

    digitalWrite(GND_PIN, LOW);
    digitalWrite(VCC_PIN, HIGH);
}

void loop() {
    Serial.print("X: ");
    Serial.print(map(analogRead(VRX_PIN), 0, 1023, -5, 5));
    Serial.print(", Y: ");
    Serial.print(map(analogRead(VRY_PIN), 0, 1023, -5, 5));
    Serial.print(", switch: ");
    Serial.print(digitalRead(SW_PIN) ? "OFF" : "ON");
    Serial.print('\n');

    delay(10);
}
