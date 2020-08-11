// preprocessor
#include <Wire.h>



// global variable
const int gyroY_address = 0x45;
double gyroY_error;
double gyroY;

int loopCount;



// function
inline void serialBegin() {
    Serial.begin(115200);
}

inline void wireBegin() {
    Wire.begin();
    Wire.setClock(400000);

    Wire.beginTransmission(0x68);
    Wire.write(0x6b);
    Wire.write(0x0);
    Wire.endTransmission(true);
}

inline void initVariable() {
    loopCount = 0;
}

inline int16_t readMPURegister_2Byte(int address) {
    Wire.beginTransmission(0x68);
    Wire.write(address);
    Wire.endTransmission(false);
    Wire.requestFrom(0x68, 2, true);
    
    int16_t GyYH = Wire.read();
    int16_t GyYL = Wire.read();
    
    return GyYH << 8 | GyYL;
}

inline double getGyroY_error() {
    int32_t gyroY_sum = 0;
    
    for (int i = 0; i < 1000; ++i) {
        gyroY_sum += readMPURegister_2Byte(gyroY_address);
    }

    return gyroY_sum / 1000.0;
}

inline double getGyroY() {
    return readMPURegister_2Byte(gyroY_address) - gyroY_error;
}

inline void printDescription() {
    // Serial.print("GyY = ");
    // Serial.print(GyY);
    Serial.print("gyroY = ");
    Serial.print(gyroY);
    Serial.println();
}



// main function
void setup() {
    serialBegin();
    wireBegin();

    initVariable();

    gyroY_error = getGyroY_error();
}

void loop() {
    gyroY = getGyroY();
    
    if (loopCount % 100 == 0)
        printDescription();

    ++loopCount;
}
