//********************************************
// char* title = "ex_fnd_01"
// made by Lieman at 2020.06.10
//
// description:
//	6 digit fnd example
//********************************************





#define DELAY_TIME (1000 / 60 / 6)

int fndDataPinArray[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int fndSelPinArray[6] = {5, 4, 3, 2, 1, 0};

void setup() {
    for (int i = 0; i < 8; ++i) {
        pinMode(fndDataPinArray[i], OUTPUT);
    }

    for (int i = 0; i < 6; ++i) {
        pinMode(fndSelPinArray[i], OUTPUT);
        
        digitalWrite(fndSelPinArray[i], LOW);
    }
}

void loop() {
    // 0
    digitalWrite(fndSelPinArray[0], LOW);
    digitalWrite(fndSelPinArray[1], HIGH);
    digitalWrite(fndSelPinArray[2], HIGH);
    digitalWrite(fndSelPinArray[3], HIGH);
    digitalWrite(fndSelPinArray[4], HIGH);
    digitalWrite(fndSelPinArray[5], HIGH);
    
    digitalWrite(fndDataPinArray[0], HIGH);
    digitalWrite(fndDataPinArray[1], HIGH);
    digitalWrite(fndDataPinArray[2], HIGH);
    digitalWrite(fndDataPinArray[3], HIGH);
    digitalWrite(fndDataPinArray[4], HIGH);
    digitalWrite(fndDataPinArray[5], HIGH);
    
    delay(DELAY_TIME);
    
    digitalWrite(fndDataPinArray[0], LOW);
    digitalWrite(fndDataPinArray[1], LOW);
    digitalWrite(fndDataPinArray[2], LOW);
    digitalWrite(fndDataPinArray[3], LOW);
    digitalWrite(fndDataPinArray[4], LOW);
    digitalWrite(fndDataPinArray[5], LOW);
    
    // 1
    digitalWrite(fndSelPinArray[0], HIGH);
    digitalWrite(fndSelPinArray[1], LOW);
    digitalWrite(fndSelPinArray[2], HIGH);
    digitalWrite(fndSelPinArray[3], HIGH);
    digitalWrite(fndSelPinArray[4], HIGH);
    digitalWrite(fndSelPinArray[5], HIGH);
    
    digitalWrite(fndDataPinArray[1], HIGH);
    digitalWrite(fndDataPinArray[2], HIGH);

    delay(DELAY_TIME);
    
    digitalWrite(fndDataPinArray[1], LOW);
    digitalWrite(fndDataPinArray[2], LOW);
    
    // 2
    digitalWrite(fndSelPinArray[0], HIGH);
    digitalWrite(fndSelPinArray[1], HIGH);
    digitalWrite(fndSelPinArray[2], LOW);
    digitalWrite(fndSelPinArray[3], HIGH);
    digitalWrite(fndSelPinArray[4], HIGH);
    digitalWrite(fndSelPinArray[5], HIGH);
    
    digitalWrite(fndDataPinArray[0], HIGH);
    digitalWrite(fndDataPinArray[1], HIGH);
    digitalWrite(fndDataPinArray[3], HIGH);
    digitalWrite(fndDataPinArray[4], HIGH);
    digitalWrite(fndDataPinArray[6], HIGH);
    
    delay(DELAY_TIME);
    
    digitalWrite(fndDataPinArray[0], LOW);
    digitalWrite(fndDataPinArray[1], LOW);
    digitalWrite(fndDataPinArray[3], LOW);
    digitalWrite(fndDataPinArray[4], LOW);
    digitalWrite(fndDataPinArray[6], LOW);
    
    // 3
    digitalWrite(fndSelPinArray[0], HIGH);
    digitalWrite(fndSelPinArray[1], HIGH);
    digitalWrite(fndSelPinArray[2], HIGH);
    digitalWrite(fndSelPinArray[3], LOW);
    digitalWrite(fndSelPinArray[4], HIGH);
    digitalWrite(fndSelPinArray[5], HIGH);
    
    digitalWrite(fndDataPinArray[0], HIGH);
    digitalWrite(fndDataPinArray[1], HIGH);
    digitalWrite(fndDataPinArray[2], HIGH);
    digitalWrite(fndDataPinArray[3], HIGH);
    digitalWrite(fndDataPinArray[6], HIGH);
    
    delay(DELAY_TIME);
    
    digitalWrite(fndDataPinArray[0], LOW);
    digitalWrite(fndDataPinArray[1], LOW);
    digitalWrite(fndDataPinArray[2], LOW);
    digitalWrite(fndDataPinArray[3], LOW);
    digitalWrite(fndDataPinArray[6], LOW);
    
    // 4
    digitalWrite(fndSelPinArray[0], HIGH);
    digitalWrite(fndSelPinArray[1], HIGH);
    digitalWrite(fndSelPinArray[2], HIGH);
    digitalWrite(fndSelPinArray[3], HIGH);
    digitalWrite(fndSelPinArray[4], LOW);
    digitalWrite(fndSelPinArray[5], HIGH);
    
    digitalWrite(fndDataPinArray[1], HIGH);
    digitalWrite(fndDataPinArray[2], HIGH);
    digitalWrite(fndDataPinArray[5], HIGH);
    digitalWrite(fndDataPinArray[6], HIGH);
    
    delay(DELAY_TIME);
    
    digitalWrite(fndDataPinArray[1], LOW);
    digitalWrite(fndDataPinArray[2], LOW);
    digitalWrite(fndDataPinArray[5], LOW);
    digitalWrite(fndDataPinArray[6], LOW);
    
    // 5
    digitalWrite(fndSelPinArray[0], HIGH);
    digitalWrite(fndSelPinArray[1], HIGH);
    digitalWrite(fndSelPinArray[2], HIGH);
    digitalWrite(fndSelPinArray[3], HIGH);
    digitalWrite(fndSelPinArray[4], HIGH);
    digitalWrite(fndSelPinArray[5], LOW);
    
    digitalWrite(fndDataPinArray[0], HIGH);
    digitalWrite(fndDataPinArray[2], HIGH);
    digitalWrite(fndDataPinArray[3], HIGH);
    digitalWrite(fndDataPinArray[5], HIGH);
    digitalWrite(fndDataPinArray[6], HIGH);
    
    delay(DELAY_TIME);
    
    digitalWrite(fndDataPinArray[0], LOW);
    digitalWrite(fndDataPinArray[2], LOW);
    digitalWrite(fndDataPinArray[3], LOW);
    digitalWrite(fndDataPinArray[5], LOW);
    digitalWrite(fndDataPinArray[6], LOW);
    
//    // 6
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], LOW);
//    digitalWrite(fndDataPinArray[2], HIGH);
//    digitalWrite(fndDataPinArray[3], HIGH);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], LOW);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // 7
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], HIGH);
//    digitalWrite(fndDataPinArray[2], HIGH);
//    digitalWrite(fndDataPinArray[3], LOW);
//    digitalWrite(fndDataPinArray[4], LOW);
//    digitalWrite(fndDataPinArray[5], LOW);
//    digitalWrite(fndDataPinArray[6], LOW);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], LOW);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // 8
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], HIGH);
//    digitalWrite(fndDataPinArray[2], HIGH);
//    digitalWrite(fndDataPinArray[3], HIGH);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], LOW);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // 9
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], HIGH);
//    digitalWrite(fndDataPinArray[2], HIGH);
//    digitalWrite(fndDataPinArray[3], HIGH);
//    digitalWrite(fndDataPinArray[4], LOW);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], LOW);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // A
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], HIGH);
//    digitalWrite(fndDataPinArray[2], HIGH);
//    digitalWrite(fndDataPinArray[3], LOW);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], LOW);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // b
//    digitalWrite(fndDataPinArray[0], LOW);
//    digitalWrite(fndDataPinArray[1], LOW);
//    digitalWrite(fndDataPinArray[2], HIGH);
//    digitalWrite(fndDataPinArray[3], HIGH);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], LOW);
//    delay(DELAY_TIME);
//    
//    // C
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], LOW);
//    digitalWrite(fndDataPinArray[2], LOW);
//    digitalWrite(fndDataPinArray[3], HIGH);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], LOW);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], LOW);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // d
//    digitalWrite(fndDataPinArray[0], LOW);
//    digitalWrite(fndDataPinArray[1], HIGH);
//    digitalWrite(fndDataPinArray[2], HIGH);
//    digitalWrite(fndDataPinArray[3], HIGH);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], LOW);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], LOW);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // E
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], LOW);
//    digitalWrite(fndDataPinArray[2], LOW);
//    digitalWrite(fndDataPinArray[3], HIGH);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], LOW);
//    digitalWrite(fndSelPinArray[3], HIGH);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
//    
//    // F
//    digitalWrite(fndDataPinArray[0], HIGH);
//    digitalWrite(fndDataPinArray[1], LOW);
//    digitalWrite(fndDataPinArray[2], LOW);
//    digitalWrite(fndDataPinArray[3], LOW);
//    digitalWrite(fndDataPinArray[4], HIGH);
//    digitalWrite(fndDataPinArray[5], HIGH);
//    digitalWrite(fndDataPinArray[6], HIGH);
//    digitalWrite(fndDataPinArray[7], LOW);
//    
//    digitalWrite(fndSelPinArray[0], HIGH);
//    digitalWrite(fndSelPinArray[1], HIGH);
//    digitalWrite(fndSelPinArray[2], HIGH);
//    digitalWrite(fndSelPinArray[3], LOW);
//    digitalWrite(fndSelPinArray[4], HIGH);
//    digitalWrite(fndSelPinArray[5], HIGH);
//    delay(DELAY_TIME);
}
