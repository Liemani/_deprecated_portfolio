//********************************************
// char* title = "ex_switch_09"
// made by Lieman at 2020.06.10
//
// description:
//	switch example
//  brightness along time test
//********************************************





// constant
const int ledPinArray[] = {13, 12, 11, 10, 9, 8, 7, 6};





// main function
void setup() {
    for (int i = 0; i < 8; ++i) {
        pinMode(ledPinArray[i], OUTPUT);
        
        digitalWrite(ledPinArray[i], LOW);
    }
}

void loop() {
    digitalWrite(ledPinArray[0], HIGH);
    digitalWrite(ledPinArray[1], HIGH);
    digitalWrite(ledPinArray[2], HIGH);
    digitalWrite(ledPinArray[3], HIGH);
    digitalWrite(ledPinArray[4], HIGH);
    digitalWrite(ledPinArray[5], HIGH);
    digitalWrite(ledPinArray[6], HIGH);
    digitalWrite(ledPinArray[7], HIGH);
    
    for (int i = 0; i < 1; ++i) {
        delay(1);
        digitalWrite(ledPinArray[i], LOW);
    }

    delay(12);
}
