// preprocessor
#include <string.h>
#include <stdlib.h>

#define MOTOR_PIN_FL 6
#define MOTOR_PIN_FR 10
#define MOTOR_PIN_BL 5
#define MOTOR_PIN_BR 9



// variable
const int MOTOR_ARRAY[] = {MOTOR_PIN_FL, MOTOR_PIN_FR, MOTOR_PIN_BL, MOTOR_PIN_BR};



// function
void printInput(const char* word1, const char* word2) {
//    static int character;
//    static int i;
//    i = 0;
    Serial.println();
    
//    while (character = word1[i]) {
//        Serial.print(character, HEX);
//        Serial.print(' ');
//        ++i;
//    }
    Serial.print(atoi(word1), HEX);
    Serial.println();

    Serial.print(atoi(word2), HEX);
    Serial.println();
}



// main function
void setup() {
    Serial1.begin(115200);
    Serial1.println(' ');
}

void loop() {
    static int shouldStop = true;
    
    
    if (Serial1.available()) {
        static int testCount = 0;
        static int character;
        static char buffer[10];
        static int bufferIndex = 0;
    
        character = Serial1.read();
        ++testCount;
        Serial.println();
        Serial.println(testCount);

        if (character != '.') {
            buffer[bufferIndex] = character;
            
            if (bufferIndex != 9)
                ++bufferIndex;
        } else {
            buffer[bufferIndex] = '\0';
            bufferIndex = 0;

            static char* word1;
            static char* word2;
            word1 = strtok(buffer, " ");
            word2 = strtok(NULL, " ");
            printInput(word1, word2);

            static int motorNumber;
            static int dutyCycle;
            motorNumber = atoi(word1);
            dutyCycle = atoi(word2);

            if (0 <= motorNumber && motorNumber <= 3
                && 0 <= dutyCycle && dutyCycle <= 255) {
                analogWrite(MOTOR_ARRAY[motorNumber], dutyCycle);
            }
        }

    }
}
