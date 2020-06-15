//********************************************
// char* title = "ex_buzzer_01"
// made by Lieman at 2020.06.12
//
// description:
//  buzzer example
//********************************************





int pinGnd = 5;
int pinBuzzer = 3;

// 3 octave - Do, Re, Mi, Fa, So, La, Ti, 4 octave - Do
float aPitchData[8] = {130.81, 146.83, 164.81, 174.61, 195.99, 220.00, 246.94, 261.62};

void setup() {
    pinMode(pinGnd, OUTPUT);
    digitalWrite(pinGnd, LOW);
    pinMode(pinBuzzer, OUTPUT);
}

void loop() {
    for (int i = 0; i < 8; ++i) {
        tone(pinBuzzer, aPitchData[i]);
        delay(1000);
        noTone(pinBuzzer);
    }
    delay(1000);
}
