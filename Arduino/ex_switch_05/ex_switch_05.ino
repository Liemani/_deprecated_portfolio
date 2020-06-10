//********************************************
// char* title = "ex_switch_05"
// made by Lieman at 2020.06.10
//
// description:
//	switch example
//********************************************





// led control checking switch edge

int ledArray[] = {13, 12, 11, 10};
int switchArray[] = {9, 8, 7, 6};

boolean isLedOnArray[4] = {false};

boolean switchPreValArray[4] = {false};
boolean switchCurVal = false;

void setup() {
    for (int i = 0; i < 4; ++i) {
        pinMode(ledArray[i], OUTPUT);
        pinMode(switchArray[i], INPUT);

        digitalWrite(ledArray[i], isLedOnArray[i]);
    }
}

void loop() {
    for (int i = 0; i < 4; ++i) {
        switchCurVal = digitalRead(switchArray[i]);
        
        if (switchCurVal == true && switchPreValArray[i] == false) {
            isLedOnArray[i] = !isLedOnArray[i];
            digitalWrite(ledArray[i], isLedOnArray[i]);
        }
        
        switchPreValArray[i] = switchCurVal;
    }
}
