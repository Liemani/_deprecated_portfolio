//********************************************
// char* title = "ex_switch_08"
// made by Lieman at 2020.06.10
//
// description:
//	switch example
//  use interrupt
//********************************************





// constant
const int ledPinArray[] = {13, 12, 11, 10, 9, 8, 7, 6};
const int switchPinArray[] = {3, 2};




// global variable
uint8_t count = 0;

boolean isOn = false;



// main function
void setup() {
    for (int i = 0; i < 8; ++i) {
        pinMode(ledPinArray[i], OUTPUT);
        
        digitalWrite(ledPinArray[i], LOW);
    }

    pinMode(switchPinArray[0], INPUT);
    pinMode(switchPinArray[1], INPUT);

    attachInterrupt(1, switch1Down, RISING);
    attachInterrupt(0, switch2Down, RISING);
}

void displayLED() {
    for (int i = 0; i < 8; ++i) {
        digitalWrite(ledPinArray[i], 0x01 & isOn & (count >> (7 - i)));
    }
}

void loop() {
    isOn = !isOn;
    
    displayLED();

    delay(500);
}

void switch1Down() {
    ++count;
    displayLED();
}

void switch2Down() {
    --count;
    displayLED();
}
