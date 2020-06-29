//********************************************
// const char* title = "SoftwareSerial"
// made by Lieman at 2020.06.26
//
// description:
//	Serial example
//  Transfer data from pc to raspberry or from raspberry to pc.
//  In Windows, Enter key make 0x0D0A
//  But I tried to input 0x0A0D, and terminal worked as intended well
//********************************************





#include <SoftwareSerial.h>

int RX = A0;
int TX = A1;
int incomingByte = 0;
SoftwareSerial raspSerial = SoftwareSerial(RX, TX);
char character;
char hexedCharacter[2];
int target;

void setup() {
    raspSerial.begin(115200);
    Serial.begin(115200);
}

void loop() {
    if (Serial.available() > 0) {
        character = Serial.read();
        raspSerial.write(character);

        if (character == 10) {
            raspSerial.write(13);
        }
    }

    if (raspSerial.available() > 0) {
        character = raspSerial.read();

        if (character == 13) {
            Serial.write(10);
        }
        
        Serial.write(character);
    }
}