//********************************************
// char* title = "ex_switch_03"
// made by Lieman at 2020.06.10
//
// description:
//	switch example
//********************************************





int ledArray[] = {13, 12, 11, 10};
int switchArray[] = {9, 8, 7, 6};

bool isLedOnArray[4] = {false};
bool isSwitchOn[4] = {false};

void setup() {
    for (int i = 0; i < 4; ++i) {
        pinMode(ledArray[i], OUTPUT);
        pinMode(switchArray[i], INPUT);

        digitalWrite(ledArray[i], isLedOnArray[i]);
    }
}

void loop() {
    for (int i = 0; i < 4; ++i) {
        if (digitalRead(switchArray[i])) {
            if (!isSwitchOn[i]) {
                isSwitchOn[i] = true;
                isLedOnArray[i] = !isLedOnArray[i];
                digitalWrite(ledArray[i], isLedOnArray[i]);
            }
        } else {
            if (isSwitchOn[i]) {
                isSwitchOn[i] = false;
            }
        }
    }
}
