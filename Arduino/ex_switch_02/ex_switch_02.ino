int switchArray[] = {13, 12, 11, 10};

void setup() {
    Serial.begin(115200);

    for (int i = 0; i < 4; ++i) {
        pinMode(switchArray[i], INPUT);
    }

    Serial.print('\n');
    Serial.print('\n');
    Serial.print("[Application start]\n");
    Serial.print("ECHO >> ");
}

void loop() {
    for (int i = 0; i < 4; ++i) {
        if (digitalRead(switchArray[i])) {
            Serial.print(i);
            Serial.print("push\n");
            delay(300);
        }
    }
}

void serialEvent(void) {
    char data;
    if (Serial.available() > 0) {
        data = Serial.read();
        Serial.write(data);

        if (data == '\n') {
            Serial.print("ECHO >> ");
        }
    }
}
