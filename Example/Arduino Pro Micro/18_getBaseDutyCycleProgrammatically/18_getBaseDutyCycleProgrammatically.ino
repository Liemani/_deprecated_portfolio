// preprocessor
#include <Wire.h>

#define MOTOR_PIN_FL 6
#define MOTOR_PIN_FR 10
#define MOTOR_PIN_RL 5
#define MOTOR_PIN_RR 9

#define BASE_DUTY_CYCLE_FL 106
#define BASE_DUTY_CYCLE_FR 133
#define BASE_DUTY_CYCLE_RL 152
#define BASE_DUTY_CYCLE_RR 133

#define MPU_SENSOR_REGISTER_ADDRESS 0x3b

#define ANGULAR_VELOCITY_STRENGTH (0.01)
#define ANGLE_STRENGTH (0.005)


// variable

// class
class MOTORS {
private:
    static const int MOTOR_PIN_ARRAY[4];
    static int BASE_DUTY_CYCLE_ARRAY[4];

    static double dutyCycleMultipleArray[4];
    
public:
    static void reset() {
        for (int i = 0; i < 4; ++i) {
            dutyCycleMultipleArray[i] = 0;
        }
    }
    
    static void begin() {
        Serial.begin(115200);
        Serial1.begin(115200);

        reset();
    }

    static void trace(double* angularVelocity, double* angle) {
        static double angularSupplement[3];
        
        for (int i = 0; i < 3; ++i) {
            angularSupplement[i] =
                + ANGULAR_VELOCITY_STRENGTH * angularVelocity[i]
                + ANGLE_STRENGTH * angle[i];
        }
        
        dutyCycleMultipleArray[0] =
            - angularSupplement[0]
            - angularSupplement[1]
            - angularSupplement[2];

        dutyCycleMultipleArray[1] =
            - angularSupplement[0]
            + angularSupplement[1]
            + angularSupplement[2];

        dutyCycleMultipleArray[2] =
            + angularSupplement[0]
            - angularSupplement[1]
            + angularSupplement[2];

        dutyCycleMultipleArray[3] =
            + angularSupplement[0]
            + angularSupplement[1]
            - angularSupplement[2];
        
        for (int i = 0; i < 4; ++i) {
            int dutyCycle;
            dutyCycle = int (BASE_DUTY_CYCLE_ARRAY[i] + dutyCycleMultipleArray[i]);
            
            analogWrite(MOTOR_PIN_ARRAY[i], dutyCycle);
        }
    }

    static void setDutyCycle(int index, int dutyCycle) {
        BASE_DUTY_CYCLE_ARRAY[index] = dutyCycle;
    }

    static void stop() {
        for (int i = 0; i < 4; ++i) {
            analogWrite(MOTOR_PIN_ARRAY[i], 0);
        }
    }

    static void printDescription() {
        Serial.println();

        Serial.print("Base Duty Cycle: [");
        
        for (int i = 0; i < 4; ++i) {
            Serial.print(BASE_DUTY_CYCLE_ARRAY[i]);
            Serial.print(", ");
        }

        Serial.print("]");

        Serial.println();

        Serial.print("Duty Cycle Multiple: [");
        
        for (int i = 0; i < 4; ++i) {
            Serial.print(dutyCycleMultipleArray[i]);
            Serial.print(", ");
        }

        Serial.print("]");

        Serial.println();
    }

    static int getDutyCycle(int index) {
        return BASE_DUTY_CYCLE_ARRAY[index] ;
    }
};

const int MOTORS::MOTOR_PIN_ARRAY[4] = {MOTOR_PIN_FL, MOTOR_PIN_FR, MOTOR_PIN_RL, MOTOR_PIN_RR};
int MOTORS::BASE_DUTY_CYCLE_ARRAY[4] = {BASE_DUTY_CYCLE_FL, BASE_DUTY_CYCLE_FR, BASE_DUTY_CYCLE_RL, BASE_DUTY_CYCLE_RR};

double MOTORS::dutyCycleMultipleArray[4];



class MPU {
private:
    // class property
    static const int sensorRegisterAddress;

    static int sensorValue[7];
    static double sensorValue_average[7];

    static double acceleration[3];
    static double velocity[3];

    static double angularVelocity[3];
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
            velocity[i] += acceleration[i] * elapsedTime / 1000000;
        }
        
        for (int i = 0; i < 3; ++i) {
            angularVelocity[i] = (sensorValue[i + 4] - sensorValue_average[i + 4]) / 131;
            angle[i] += angularVelocity[i] * elapsedTime / 1000000;
        }

        previousTime = currentTime;
    }

    static double* getAngularVelocityArray() {
        return angularVelocity;
    }

    static double* getAngleArray() {
        return angle;
    }

    static void printDescription() {
        Serial.println();
        
        Serial.print("@Acceleration: [");
        if (acceleration[0] >= 0) Serial.print(' ');
        Serial.print(acceleration[0]);
        Serial.print(", ");
        if (acceleration[1] >= 0) Serial.print(' ');
        Serial.print(acceleration[1]);
        Serial.print(", ");
        if (acceleration[2] >= 0) Serial.print(' ');
        Serial.print(acceleration[2]);
        Serial.print("]");

        Serial.println();
        
        Serial.print("Velocity: [");
        if (velocity[0] >= 0) Serial.print(' ');
        Serial.print(velocity[0]);
        Serial.print(", ");
        if (velocity[1] >= 0) Serial.print(' ');
        Serial.print(velocity[1]);
        Serial.print(", ");
        if (velocity[2] >= 0) Serial.print(' ');
        Serial.print(velocity[2]);
        Serial.print("]");

        Serial.println();

        Serial.print("Temp: ");
        if (sensorValue[3] >= 0) Serial.print(' ');
        Serial.print((sensorValue[3] - sensorValue_average[3]) / 340 + 36.53);

        Serial.println();

        Serial.print("@Angular velocity: [");
        if (angularVelocity[0] >= 0) Serial.print(' ');
        Serial.print(angularVelocity[0]);
        Serial.print(", ");
        if (angularVelocity[1] >= 0) Serial.print(' ');
        Serial.print(angularVelocity[1]);
        Serial.print(", ");
        if (angularVelocity[2] >= 0) Serial.print(' ');
        Serial.print(angularVelocity[2]);
        Serial.print("]");
        
        Serial.println();

        Serial.print("Angle: [");
        if (angle[0] >= 0) Serial.print(' ');
        Serial.print(angle[0]);
        Serial.print(", ");
        if (angle[1] >= 0) Serial.print(' ');
        Serial.print(angle[1]);
        Serial.print(", ");
        if (angle[2] >= 0) Serial.print(' ');
        Serial.print(angle[2]);
        Serial.print("]");
        
        Serial.println();
    }
};

const int MPU::sensorRegisterAddress = MPU_SENSOR_REGISTER_ADDRESS;

int MPU::sensorValue[7];
double MPU::sensorValue_average[7];

double MPU::acceleration[3];
double MPU::velocity[3];

double MPU::angularVelocity[3];
double MPU::angle[3];



// main function
void setup() {
    MPU::begin();
    MOTORS::begin();
}

void loop() {
    static int shouldStop = true;
    
    if (!shouldStop) {
        MPU::trace();
        MOTORS::trace(MPU::getAngularVelocityArray(), MPU::getAngleArray());
    }

    static int character = 0;
    
    static char buffer[10];
    static int bufferIndex = 0;

    static int selectedMotor = 0;    // store 4bit data(motor1, motor2, motor3, motor4)
    
    if (Serial1.available()) {
        character = Serial1.read();

        if (character != 32) {    // 32 == ' '
            if (bufferIndex < 10) {
                buffer[bufferIndex] = character;
                
                ++bufferIndex;
            }
        } else {
            if ('0' <= buffer[0] && buffer[0] <= '3') {
                selectedMotor = 0x1 << (buffer[0] - '0');
            } else if (buffer[0] == 'a') {
                selectedMotor = 0xF;    // 1111
            } else if (buffer[0] == 'd') {
                selectedMotor = 0x9;    // 1001
            } else if (buffer[0] == 'p') {
                selectedMotor = 0x6;    // 0110
            } else if (buffer[0] == 'l') {
                selectedMotor = 0x5;    // 0101
            } else if (buffer[0] == 'r') {
                selectedMotor = 0xA;    // 1010
            } else if (buffer[0] == 'f') {
                selectedMotor = 0x3;    // 0011
            } else if (buffer[0] == 'b') {
                selectedMotor = 0xB;    // 1100
            } else if (buffer[0] == 's') {
                shouldStop = true;
                MOTORS::stop();
            } else if (buffer[0] == 'c') {
                Serial.begin(115200);
            } else if (buffer[0] == 'g') {
                shouldStop = false;
            } else if (buffer[0] == 'i') {
                MOTORS::reset();
                MPU::reset();
            }
            
            if (buffer[1] == '+') {
                for (int i = 0; i < 4; ++i) {
                    if ((selectedMotor >> i) & 0x1) {
                        MOTORS::setDutyCycle(i, MOTORS::getDutyCycle(i) + 1);
                    }
                }
            } else if (buffer[1] == '-') {
                for (int i = 0; i < 4; ++i) {
                    if ((selectedMotor >> i) & 0x1) {
                        MOTORS::setDutyCycle(i, MOTORS::getDutyCycle(i) - 1);
                    }
                }
            }
            
            MOTORS::printDescription();
            bufferIndex = 0;
        }
    }

    static int loopCount = 0;
    ++loopCount;
    if (loopCount % 100 == 0) {
        MPU::printDescription();
    }
}
