// preprocessor
#define MOTOR_PIN_FL 6
#define MOTOR_PIN_FR 10
#define MOTOR_PIN_RL 5
#define MOTOR_PIN_RR 9



// variable

// class
class MOTORS {
private:
    static const int MOTOR_PIN_ARRAY[4];
    static int dutyCycleArray[4];
    
public:
    static void begin() {
        Serial.begin(115200);
        Serial1.begin(115200);
        
        for (int i = 0; i < 4; ++i)
            analogWrite(MOTOR_PIN_ARRAY[i], dutyCycleArray[i]);
    }

    static void setDutyCycle(int index, int dutyCycle) {
        dutyCycleArray[index] = dutyCycle;
        analogWrite(MOTOR_PIN_ARRAY[index], dutyCycle);
    }

    static void printDescription() {
        Serial.println();
        
        for (int i = 0; i < 4; ++i) {
            Serial.print(dutyCycleArray[i]);
            Serial.print("  ");
        }

        Serial.println();
    }

    static int getDytyCycle(int index) {
        return dutyCycleArray[index] ;
    }
};

const int MOTORS::MOTOR_PIN_ARRAY[4] = {MOTOR_PIN_FL, MOTOR_PIN_FR, MOTOR_PIN_RL, MOTOR_PIN_RR};

int MOTORS::dutyCycleArray[4] = {106, 133, 152, 133};



// main function
void setup() {
    MOTORS::begin();
}

void loop() {
    static int character = 0;
    
    static char buffer[10];
    static int count = 0;

    static int selectedMortor = 0;    // store 4bit data(motor1, motor2, motor3, motor4)
    
    if (Serial1.available()) {
        character = Serial1.read();

        if (character != 32) {    // 32 == ' '
            if (count < 10) {
                buffer[count] = character;
                
                ++count;
            }
        } else {
            if ('0' <= buffer[0] && buffer[0] <= '3') {
                selectedMortor = 0x1 << (buffer[0] - '0');
            } else if (buffer[0] == 'a') {
                selectedMortor = 0xF;    // 1111
            } else if (buffer[0] == 'd') {
                selectedMortor = 0x9;    // 1001
            } else if (buffer[0] == 'p') {
                selectedMortor = 0x6;    // 0110
            } else if (buffer[0] == 'l') {
                selectedMortor = 0x5;    // 0101
            } else if (buffer[0] == 'r') {
                selectedMortor = 0xA;    // 1010
            } else if (buffer[0] == 'f') {
                selectedMortor = 0x3;    // 0011
            } else if (buffer[0] == 'b') {
                selectedMortor = 0xB;    // 1100
            } else if (buffer[0] == 's') {
                for (int i = 0; i < 4; ++i) {
                    MOTORS::setDutyCycle(i, MOTORS::getDytyCycle(i) - 10);
                }
            }
            
            if (buffer[1] == '+') {
                for (int i = 0; i < 4; ++i) {
                    if ((selectedMortor >> i) & 0x1) {
                        MOTORS::setDutyCycle(i, MOTORS::getDytyCycle(i) + 1);
                    }
                }
            } else if (buffer[1] == '-') {
                for (int i = 0; i < 4; ++i) {
                    if ((selectedMortor >> i) & 0x1) {
                        MOTORS::setDutyCycle(i, MOTORS::getDytyCycle(i) - 1);
                    }
                }
            }
            
            MOTORS::printDescription();
            count = 0;
        }
    }

//    static int loopCount = 0;
//    
//    if (loopCount % 100 == 0)
//        MOTORS::printDescription();
//
//    ++loopCount;
}
