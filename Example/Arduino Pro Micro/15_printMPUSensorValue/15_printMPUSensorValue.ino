// preprocessor
#include <Wire.h>



// class
class MPU {
private:
    // class property
    static const int sensorValueAddress = 0x3b;

    static int sensorValue[7];
    static double sensorValue_average[7];

    static double speed[3];
    static double angle[3];


    
    // class method
    static void readSensor() {
        static int high_byte;
        static int low_byte;
        
        Wire.beginTransmission(0x68);
        Wire.write(sensorValueAddress);
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
            speed[i] += 9.8 * (sensorValue[i] - sensorValue_average[i]) / 16384 * elapsedTime / 1000000;
        }
        
        for (int i = 4; i < 7; ++i) {
            angle[i - 4] += (sensorValue[i] - sensorValue_average[i]) / 131 * elapsedTime / 1000000;
        }

        previousTime = currentTime;
    }

    static void printDescription() {
        Serial.println();
        
        Serial.print("Accel: [");
        if (sensorValue[0] >= 0) Serial.print(' ');
        Serial.print(speed[0]);
        Serial.print(", ");
        if (sensorValue[1] >= 0) Serial.print(' ');
        Serial.print(speed[1]);
        Serial.print(", ");
        if (sensorValue[2] >= 0) Serial.print(' ');
        Serial.print(speed[2]);
        Serial.print("]");

        Serial.println();

        Serial.print("Temp: ");
        if (sensorValue[3] >= 0) Serial.print(' ');
        Serial.print((sensorValue[3] - sensorValue_average[3]) / 340 + 36.53);

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

int MPU::sensorValue[7];
double MPU::sensorValue_average[7];

double MPU::speed[3] = {0};
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
