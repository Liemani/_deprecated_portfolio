void setup() {
    Serial.begin(115200);
}

void loop() {
    if (Serial.available()) {
        char inputData = Serial.read();
        
        Serial.print(inputData, HEX);
        
        if (inputData == 10) {
            Serial.println("10 entered");
        } else if (inputData == 13) {
            Serial.println("13 entered");
        }
    }
}
