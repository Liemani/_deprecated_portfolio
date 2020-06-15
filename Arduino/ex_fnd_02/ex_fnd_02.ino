//********************************************
// char* title = "ex_fnd_02"
// made by Lieman at 2020.06.10
//
// description:
//	6 digit fnd example
//********************************************





#define DELAY_TIME 2
#define DIGIT0 0
#define DURATION 2

int fndDataPinArray[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int fndSelPinArray[6] = {5, 4, 3, 2, 1, 0};

uint8_t fndData[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
//uint8_t fndSelData[] = {0x3E, 0x3D, 0x3B, 0x37, 0x2F, 0x1F};

void printFND(uint8_t fndCharacter, uint8_t selection) {
    for (int i = 0; i < 6; ++i) {
        digitalWrite(fndSelPinArray[i], HIGH);
    }

    digitalWrite(fndSelPinArray[selection], LOW);

    for (int i = 0; i < 8; ++i) {
        fndCharacter
    }
    
    setCharacter
    duration
    setclear
}




void fndDataOut(uint8_t data) {
    for (int i = 0; i < 8; ++i) {
        digitalWrite(fndDataPinArray[i], (data >> i) & 0x1);
    }
}

void fndSelOut(uint8_t data) {
    for (int i = 0; i < 6; ++i) {
        digitalWrite(fndSelData[i], (data >> i) & 0x1);
    }
}

void setup() {
    for (int i = 0; i < 8; ++i) {
        pinMode(fndDataPinArray[i], OUTPUT);

        digitalWrite(fndDataPinArray[i], LOW);
    }

    for (int i = 0; i < 6; ++i) {
        pinMode(fndSelPinArray[i], OUTPUT);
        
        digitalWrite(fndSelPinArray[i], HIGH);
    }
}

void loop() {
    fndSelOut(fndSelData[0]);
    for (int i = 0; i < 16; ++i) {
        fndDataOut(fndData[i]);
        delay(1000);
    }
}
