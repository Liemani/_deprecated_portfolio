// preprocessor
#include <Wire.h>



// class
class GyroY {
private:
    static int mpu_address;

    static double gyroYSensorValue_average;
    
    static double angle;

    static int getGyroYSensorValue() {
        Wire.beginTransmission(0x68);
        Wire.write(mpu_address);
        Wire.endTransmission(false);
        Wire.requestFrom(0x68, 2, true);

        static int high_byte;
        static int low_byte;
        
        high_byte = Wire.read();
        low_byte = Wire.read();
        
        return high_byte << 8 | low_byte;
    }

    static void setGyroYSensorValue_average() {
        const int sampleCount = 1000;
        long int sum = 0;
        
        for (int i = 0; i < sampleCount; ++i) {
            sum += getGyroYSensorValue();
            delay(1);
        }
    
        gyroYSensorValue_average = sum / double(sampleCount);
    }

    static inline double getAngularVelocity() {
        return (getGyroYSensorValue() - gyroYSensorValue_average) / 131;
    }
    
public:
    static void begin() {
        Wire.begin();
        Wire.setClock(400000);
    
        Wire.beginTransmission(0x68);
        Wire.write(0x6b);
        Wire.write(0x0);
        Wire.endTransmission(true);

        setGyroYSensorValue_average();
    }

    static void trace() {
        static long int previousTime = micros();
        static long int currentTime;
        static int elapsedTime;

        currentTime = micros();
        
        elapsedTime = currentTime - previousTime;

        angle += getAngularVelocity() * elapsedTime / 1000000;

        previousTime = currentTime;
    }

    static double getAngle() {
        return angle;
    }
};

int GyroY::mpu_address = 0x45;

double GyroY::gyroYSensorValue_average;

double GyroY::angle = 0;



// function
inline void serialBegin() {
    Serial.begin(115200);
}

inline void printDescription() {
    Serial.println();
    
//    Serial.print("GyY = ");
//    Serial.print(GyY);
//    
//    Serial.print("angularVelocity_raw(): ");
//    Serial.println(GyroY::getAngularVelocity_raw());
//    
//    Serial.print("angularVelocity_average: ");
//    Serial.println(GyroY::angularVelocity_average);
//    
//    Serial.print("angularVelocity_modified: ");
//    Serial.println(GyroY::getAngularVelocity_modified());
    
    Serial.print("angle: ");
    Serial.println(GyroY::getAngle());
}



// main function
void setup() {
    serialBegin();
    
    GyroY::begin();
}

void loop() {
    static int loopCount = 0;

    GyroY::trace();
    
    if (loopCount % 100 == 0)
        printDescription();

    ++loopCount;
}
