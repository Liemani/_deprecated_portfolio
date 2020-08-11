#include <Wire.h>

int16_t readByte;

void setup() {
    Serial.begin(115200);

    Wire.begin();
    Wire.setClock(400000);

    Wire.beginTransmission(0x68);
    Wire.write(0x1b);
    Wire.endTransmission(false);
    Wire.requestFrom(0x68, 1, true);
    readByte = Wire.read();
}

void loop() {
    Serial.println(readByte);
    
    delay(100);
}
