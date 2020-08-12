// preprocessor
#include <Wire.h>

#define MOTOR_PIN_FL 6
#define MOTOR_PIN_FR 10
#define MOTOR_PIN_RL 5
#define MOTOR_PIN_RR 9

#define BASE_DUTY_CYCLE_FL 127
#define BASE_DUTY_CYCLE_FR 127
#define BASE_DUTY_CYCLE_RL 127
#define BASE_DUTY_CYCLE_RR 127

#define MPU_SENSOR_REGISTER_ADDRESS 0x3b



// variable

// class
class MOTORS {
private:
    static const int MOTOR_PIN_ARRAY[4];
    static const int BASE_DUTY_CYCLE_ARRAY[4];
    
    static int motorMultiplierSupplementArray[4];
    static int motorAdderSupplementArray[4];
    
    static int motorDutyCycleArray[4];
    
public:
    static void trace() {
        for (int i = 0; i < 4; ++i) {
            motorDutyCycleArray[i] = baseDutyCycle * motorMultiplierSupplementArray[i] + motorAdderSupplementArray[i];
        }
    }
};

const int MOTORS::MOTOR_PIN_ARRAY[4] = {MOTOR_PIN_FL, MOTOR_PIN_FR, MOTOR_PIN_RL, MOTOR_PIN_RR};
const int MOTORS::BASE_DUTY_CYCLE_ARRAY[4] = {BASE_DUTY_CYCLE_FL, BASE_DUTY_CYCLE_FR, BASE_DUTY_CYCLE_RL, BASE_DUTY_CYCLE_RR};

int MOTORS::motorMultiplierSupplementArray[4];
int MOTORS::motorAdderSupplementArray[4];

int MOTORS::motorDutycycleArray[4];



class MPU {
private:
    // class property
    static const int sensorRegisterAddress;

    static int sensorValue[7];
    static double sensorValue_average[7];

    static double accel[3];
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
    static void begin() {
        Wire.begin();
        Wire.setClock(400000);
    
        Wire.beginTransmission(0x68);
        Wire.write(0x6b);
        Wire.write(0x0);
        Wire.endTransmission(true);

        setSensorValue_average();
    }

    static void trace() {
        static long int previousTime = micros();
        static long int currentTime;
        static int elapsedTime;

        readSensor();
        
        currentTime = micros();
        elapsedTime = currentTime - previousTime;

        for (int i = 0; i < 3; ++i) {
            accel[i] = 9.8 * (sensorValue[i] - sensorValue_average[i]) / 16384;
            velocity[i] += accel[i] * elapsedTime / 1000000;
        }
        
        for (int i = 0; i < 3; ++i) {
            angularVelocity[i] = (sensorValue[i + 4] - sensorValue_average[i + 4]) / 131;
            angle[i] += angularVelocity[i] * elapsedTime / 1000000;
        }

        previousTime = currentTime;
    }

    static void printDescription() {
        Serial.println();
        
        Serial.print("Accel: [");
        if (accel[0] >= 0) Serial.print(' ');
        Serial.print(accel[0]);
        Serial.print(", ");
        if (accel[1] >= 0) Serial.print(' ');
        Serial.print(accel[1]);
        Serial.print(", ");
        if (accel[2] >= 0) Serial.print(' ');
        Serial.print(accel[2]);
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

        Serial.print("Angular velocity: [");
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

double MPU::accel[3];
double MPU::velocity[3] = {0};

double MPU::angularVelocity[3];
double MPU::angle[3] = {0};



// function
inline void serialBegin() {
    Serial.begin(115200);
}



// main function
void setup() {
    serialBegin();
    
    MPU::begin();
}

void loop() {
    static int loopCount = 0;

    MPU::trace();
    
    if (loopCount % 100 == 0)
        MPU::printDescription();

    ++loopCount;
}
