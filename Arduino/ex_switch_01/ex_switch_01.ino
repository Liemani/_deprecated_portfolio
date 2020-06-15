//********************************************
// char* title = "ex_switch_01"
// made by Lieman at 2020.06.10
//
// description:
//	switch example
//********************************************





#define SWITCH0 13
int count = 0;

void setup() {
    Serial.begin(115200);
    pinMode(SWITCH0, INPUT);

    Serial.print('\n');
    Serial.print('\n');
    Serial.print("Application start!");
    Serial.print('\n');
    Serial.print(sizeof(int));
    Serial.print('\n');
    Serial.print(48);
    Serial.print('\n');
    char ch = 48;
    Serial.print(ch);
    Serial.print('\n');
}

void loop() {
    if (digitalRead(SWITCH0)) {
        ++count;
        Serial.print(count);
        Serial.print("\n");
    }
}
