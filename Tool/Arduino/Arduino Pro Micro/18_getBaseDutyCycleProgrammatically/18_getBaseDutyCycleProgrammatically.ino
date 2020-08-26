// for to input Serial1, must no Serial.print()
// This doen't work!!
// preprocessor
#include <stdlib.h>
#include <string.h>

#include <Wire.h>

#define MOTOR_PIN_FL 6
#define MOTOR_PIN_FR 10
#define MOTOR_PIN_RL 5
#define MOTOR_PIN_RR 9

//#define BASE_DUTY_CYCLE_FL 106
//#define BASE_DUTY_CYCLE_FR 133
//#define BASE_DUTY_CYCLE_RL 152
//#define BASE_DUTY_CYCLE_RR 133

#define BASE_DUTY_CYCLE_FL 200
#define BASE_DUTY_CYCLE_FR 200
#define BASE_DUTY_CYCLE_RL 200
#define BASE_DUTY_CYCLE_RR 200

#define MPU_SENSOR_REGISTER_ADDRESS 0x3b

#define ACCELERATION_STRENGTH (1)
#define instantaneousVelocityChange_strength (300)

#define ANGULAR_VELOCITY_STRENGTH (1)
#define instantaneousAngleChange_strength (300)
#define ANGLE_STRENGTH (1)


// variable

// class
class MOTORS {
private:
    static const int MOTOR_PIN_ARRAY[4];
    
    static int baseDutyCycleArray[4];

    static double dutyCycleCorrectionArray[4];
    
public:
    static double instantaneousVelocityChangeSetPoint[3];
    static double instantaneousAngleChangeSetPoint[3];
    
    static void reset() {
        for (int i = 0; i < 4; ++i) {
            dutyCycleCorrectionArray[i] = 0;
        }

        for (int i = 0; i < 3; ++i) {
            instantaneousVelocityChangeSetPoint[i] = 0;
            instantaneousAngleChangeSetPoint[i] = 0;
        }
    }
    
    static void begin() {
        Serial.begin(115200);
        Serial1.begin(115200);

        reset();
    }

    static void stop() {
        for (int i = 0; i < 4; ++i) {
            analogWrite(MOTOR_PIN_ARRAY[i], 0);
        }
    }

    static inline void applyMotor(int index) {
        static int dutyCycle;
        dutyCycle = int (baseDutyCycleArray[index] + dutyCycleCorrectionArray[index]);

        if (dutyCycle < 0) dutyCycle = 0;
        if (dutyCycle > 255) dutyCycle = 255;
        
        analogWrite(MOTOR_PIN_ARRAY[index], dutyCycle);
    }

    static void trace(double* instantaneousVelocityChange, double* instantaneousAngleChange) {
        static double accelerationCorrection[3];
        static double angularCorrection[3];
        
        for (int i = 0; i < 3; ++i) {
            accelerationCorrection[i] =
                + instantaneousVelocityChange_strength * (instantaneousVelocityChangeSetPoint[i] - instantaneousVelocityChange[i]);
            
            angularCorrection[i] =
                + instantaneousAngleChange_strength * (instantaneousAngleChangeSetPoint[i] - instantaneousAngleChange[i]);
//                + ANGLE_STRENGTH * angle[i]
        }
        
        dutyCycleCorrectionArray[0] =
            + accelerationCorrection[0]
            - accelerationCorrection[1]
            + accelerationCorrection[2]
            + angularCorrection[0]
            + angularCorrection[1]
            + angularCorrection[2];

        dutyCycleCorrectionArray[1] =
            - accelerationCorrection[0]
            - accelerationCorrection[1]
            + accelerationCorrection[2]
            + angularCorrection[0]
            - angularCorrection[1]
            - angularCorrection[2];

        dutyCycleCorrectionArray[2] =
            + accelerationCorrection[0]
            + accelerationCorrection[1]
            + accelerationCorrection[2]
            - angularCorrection[0]
            + angularCorrection[1]
            - angularCorrection[2];

        dutyCycleCorrectionArray[3] =
            - accelerationCorrection[0]
            + accelerationCorrection[1]
            + accelerationCorrection[2]
            - angularCorrection[0]
            - angularCorrection[1]
            + angularCorrection[2];
        
        for (int i = 0; i < 4; ++i) {
            applyMotor(i);
        }
    }

    static int getBaseDutyCycle(int index) {
        return baseDutyCycleArray[index] ;
    }

    static void setBaseDutyCycle(int index, int dutyCycle) {
        baseDutyCycleArray[index] = dutyCycle;
        
        applyMotor(index);
    }

    static void printDescription() {
        Serial.println();

        Serial.println("MOTOR DESCRIPTION");
        Serial.println();

        Serial.print("Base Duty Cycle: [");
        
        for (int i = 0; i < 4; ++i) {
            Serial.print(baseDutyCycleArray[i]);
            Serial.print(", ");
        }

        Serial.print("]");

        Serial.println();

        Serial.print("Duty Cycle Correction: [");
        
        for (int i = 0; i < 4; ++i) {
            Serial.print(dutyCycleCorrectionArray[i]);
            Serial.print(", ");
        }

        Serial.print("]");

        Serial.println();
    }
};

const int MOTORS::MOTOR_PIN_ARRAY[4] = {MOTOR_PIN_FL, MOTOR_PIN_FR, MOTOR_PIN_RL, MOTOR_PIN_RR};
int MOTORS::baseDutyCycleArray[4] = {BASE_DUTY_CYCLE_FL, BASE_DUTY_CYCLE_FR, BASE_DUTY_CYCLE_RL, BASE_DUTY_CYCLE_RR};

double MOTORS::dutyCycleCorrectionArray[4];

double MOTORS::instantaneousVelocityChangeSetPoint[3];
double MOTORS::instantaneousAngleChangeSetPoint[3];



class MPU {
private:
    // class property
    static const int sensorRegisterAddress;

    static int sensorValue[7];
    static double sensorValue_average[7];

    static double acceleration[3];
    static double instantaneousVelocityChange[3];
    static double velocity[3];

    static double angularVelocity[3];
    static double instantaneousAngleChange[3];
    static double angle[3];


    
    // class method
    static void readSensor() {
        static int high_byte;
        static int low_byte;
        
        Wire.beginTransmission(0x68);
        Wire.write(sensorRegisterAddress);
        Wire.endTransmission(false);
        Wire.requestFrom(0x68, 14, true);

        for (int i = 0; i < 7; ++i) {
            high_byte = Wire.read();
            low_byte = Wire.read();

            sensorValue[i] = high_byte << 8 | low_byte;
        }
    }

    static void setSensorValue_average() {
        const int sampleCount = 1000;
        const int interval = 1;
        long int sum[7] = {0};
        
        for (int i = 0; i < sampleCount; ++i) {
            readSensor();
            
            for (int j = 0; j < 7; ++j) {
                sum[j] += sensorValue[j];
            }

            delay(interval);
        }

        for (int i = 0; i < 7; ++i) {
            sensorValue_average[i] = sum[i] / double(sampleCount);
        }
    }
    
public:
    static void reset() {
        for (int i = 0; i < 3; ++i) {
            velocity[i] = 0;
            
            angle[i] = 0;
        }
        
        setSensorValue_average();
    }

    static void begin() {
        Wire.begin();
        Wire.setClock(400000);
    
        Wire.beginTransmission(0x68);
        Wire.write(0x6b);
        Wire.write(0x0);
        Wire.endTransmission(true);

        reset();
    }

    static void trace() {
        static long int previousTime = micros();
        static long int currentTime;
        static int elapsedTime;

        readSensor();
        
        currentTime = micros();
        elapsedTime = currentTime - previousTime;

        for (int i = 0; i < 3; ++i) {
            acceleration[i] = 9.8 * (sensorValue[i] - sensorValue_average[i]) / 16384;
            instantaneousVelocityChange[i] = acceleration[i] * elapsedTime / 1000000;
            velocity[i] += instantaneousVelocityChange[i];

            angularVelocity[i] = (sensorValue[i + 4] - sensorValue_average[i + 4]) / 131;
            instantaneousAngleChange[i] = angularVelocity[i] * elapsedTime / 1000000;
            angle[i] += instantaneousAngleChange[i];
        }

        previousTime = currentTime;
    }

    static double* getAcceleration() {
        return acceleration;
    }

    static double* getInstantaneousVelocityChange() {
        return instantaneousVelocityChange;
    }

    static double* getVelocity() {
        return velocity;
    }

    static double* getAngularVelocityArray() {
        return angularVelocity;
    }

    static double* getInstantaneousAngleChange() {
        return instantaneousAngleChange;
    }

    static double* getAngleArray() {
        return angle;
    }

    static void printDescription() {
        Serial.println();

        Serial.println("MPU DESCRIPTION");
        Serial.println();
        
        Serial.print("@Acceleration: [");
        for (int i = 0; i < 3; ++i) {
            if (acceleration[i] >= 0) Serial.print(' ');
            Serial.print(acceleration[i]);
            Serial.print(", ");
        }
        Serial.print("]");
        Serial.println();
        
        Serial.print("Instantaneous velocity change: [");
        for (int i = 0; i < 3; ++i) {
            if (instantaneousVelocityChange[i] >= 0) Serial.print(' ');
            Serial.print(instantaneousVelocityChange[i]);
            Serial.print(", ");
        }
        Serial.print("]");
        Serial.println();
        
        Serial.print("Velocity: [");
        for (int i = 0; i < 3; ++i) {
            if (velocity[i] >= 0) Serial.print(' ');
            Serial.print(velocity[i]);
            Serial.print(", ");
        }
        Serial.print("]");
        Serial.println();
        
        Serial.println();

        Serial.print("Temp: ");
        if (sensorValue[3] >= 0) Serial.print(' ');
        Serial.print((sensorValue[3] - sensorValue_average[3]) / 340 + 36.53);
        Serial.println();
        
        Serial.println();

        Serial.print("@Angular velocity: [");
        for (int i = 0; i < 3; ++i) {
            if (angularVelocity[i] >= 0) Serial.print(' ');
            Serial.print(angularVelocity[i]);
            Serial.print(", ");
        }
        Serial.print("]");
        Serial.println();

        Serial.print("Instantaneous angle change: [");
        for (int i = 0; i < 3; ++i) {
            if (instantaneousAngleChange[i] >= 0) Serial.print(' ');
            Serial.print(instantaneousAngleChange[i]);
            Serial.print(", ");
        }
        Serial.print("]");
        Serial.println();

        Serial.print("Angle: [");
        for (int i = 0; i < 3; ++i) {
            if (angle[i] >= 0) Serial.print(' ');
            Serial.print(angle[i]);
            Serial.print(", ");
        }
        Serial.print("]");
        Serial.println();
    }
};

const int MPU::sensorRegisterAddress = MPU_SENSOR_REGISTER_ADDRESS;

int MPU::sensorValue[7];
double MPU::sensorValue_average[7];

double MPU::acceleration[3];
double MPU::instantaneousVelocityChange[3];
double MPU::velocity[3];

double MPU::angularVelocity[3];
double MPU::instantaneousAngleChange[3];
double MPU::angle[3];



// function
void printInput(const char* word1, const char* word2) {
    static int character;
    static int i;
    i = 0;

    Serial.println();
    
    while (character = word1[i]) {
        Serial.print(character, HEX);
        Serial.print(' ');
        ++i;
    }
    Serial.println();

    while (character = word2[i]) {
        Serial.print(character, HEX);
        Serial.print(' ');
        ++i;
    }
    Serial.println();
}



// main function
void setup() {
    MPU::begin();
    MOTORS::begin();
}

void loop() {
    static int shouldRun = false;
    static int shouldDebug = false;
    
    if (shouldRun) {
        MPU::trace();
        MOTORS::trace(MPU::getInstantaneousAngleChange(), MPU::getInstantaneousAngleChange());
    }

    if (Serial1.available()) {
        static int character;
        static char buffer[10];
        static int bufferIndex = 0;
    
        character = Serial1.read();
            
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

            static int motorNumber;
            static int dutyCycle;
            motorNumber = atoi(word1);
            dutyCycle = atoi(word2);

            static int selectedMotor;    // store 4bit data(motor1, motor2, motor3, motor4)
            selectedMotor = 0;
            if ('0' <= word1[0] && word1[0] <= '3') {
                selectedMotor = 0x1 << motorNumber;
            } else if (word1[0] == 'r') {
                selectedMotor = 0xF;    // 1111
            } else if (word1[0] == 'q') {
                selectedMotor = 0x9;    // 1001
            } else if (word1[0] == 'e') {
                selectedMotor = 0x6;    // 0110
            } else if (word1[0] == 'd') {
                selectedMotor = 0x5;    // 0101
            } else if (word1[0] == 'a') {
                selectedMotor = 0xA;    // 1010
            } else if (word1[0] == 's') {
                selectedMotor = 0x3;    // 0011
            } else if (word1[0] == 'w') {
                selectedMotor = 0xC;    // 1100
            } else if (word1[0] == 'x') {
                shouldRun = false;
                MOTORS::stop();
            } else if (word1[0] == 'z') {
                shouldRun = true;
            } else if (word1[0] == 'c') {
                MOTORS::reset();
                MPU::reset();
            } else if (word1[0] == 'b') {
                shouldDebug = !shouldDebug;
            } else if (word1[0] == 'm') {
                MOTORS::printDescription();
                MPU::printDescription();
            }

            if (selectedMotor) {
                if (word2[0] == '+') {
                    for (int i = 0; i < 4; ++i) {
                        if ((selectedMotor >> i) & 0x1) {
                            MOTORS::setBaseDutyCycle(i, MOTORS::getBaseDutyCycle(i) + 1);
                        }
                    }
                } else if (word2[0] == '-') {
                    for (int i = 0; i < 4; ++i) {
                        if ((selectedMotor >> i) & 0x1) {
                            MOTORS::setBaseDutyCycle(i, MOTORS::getBaseDutyCycle(i) - 1);
                        }
                    }
                } else {
                    for (int i = 0; i < 4; ++i) {
                        if ((selectedMotor >> i) & 0x1) {
                            MOTORS::setBaseDutyCycle(i, dutyCycle);
                        }
                    }
                }
            }
        }
    }

    static int loopCount = 0;
    ++loopCount;
    if (shouldDebug == true && loopCount % 100 == 0) {
        MOTORS::printDescription();
        MPU::printDescription();
    }
}
