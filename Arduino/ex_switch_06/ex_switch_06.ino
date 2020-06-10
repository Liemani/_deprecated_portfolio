//********************************************
// char* title = "ex_switch_06"
// made by Lieman at 2020.06.10
//
// description:
//	switch example
//********************************************





// led control checking switch edge

int ledArray[] = {13, 12};
int switchArray[] = {11, 10};

boolean isLedOnArray[2] = {LOW};

boolean switchPreValArray[2] = {false};
boolean switchCurVal = false;

boolean shouldDelay = false;

void setup() {
    for (int i = 0; i < 2; ++i) {
        pinMode(ledArray[i], OUTPUT);
        pinMode(switchArray[i], INPUT);

        digitalWrite(ledArray[i], isLedOnArray[i]);
    }
}

void loop() {
    for (int i = 0; i < 2; ++i) {
        if (isLedOnArray[i] == HIGH) {
            digitalWrite(ledArray[i], !digitalRead(ledArray[i]));
            shouldDelay = true;
        }
    }
    
    for (int i = 0; i < 2; ++i) {
        switchCurVal = digitalRead(switchArray[i]);
        
        if (switchCurVal == true && switchPreValArray[i] == false) {
            isLedOnArray[i] = !isLedOnArray[i];
            digitalWrite(ledArray[i], isLedOnArray[i]);
        }
        
        switchPreValArray[i] = switchCurVal;
    }

    if (shouldDelay) {
        delay(300);
        shouldDelay = false;
    }
}
