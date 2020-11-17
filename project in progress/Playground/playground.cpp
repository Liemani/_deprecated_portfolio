// preprocessor
//#include <Wire.h>
#include <stdio.h>
#include <time.h>



// class
class MPU {
private:
    // class property
    static const int sensorValueAddress = 0x3b;

    static int sensorValue[7];
    static double sensorValue_average[7];

    static double angle[3];



    // class method
    static void readSensor() {
        static int high_byte;
        static int low_byte;

        //Wire.beginTransmission(0x68);
        //Wire.write(sensorValueAddress);
        //Wire.endTransmission(false);
        //Wire.requestFrom(0x68, 14, true);

        for (int i = 0; i < 14; ++i) {
            //high_byte = Wire.read();
            //low_byte = Wire.read();

            //sensorValue[i] = high_byte << 8 | low_byte;
            sensorValue[i] = 0;
        }
    }

    static void setSensorValue_average() {
        const int sampleCount = 1000;
        const int interval = 1;
        long int sum[7] = { 0 };

        for (int i = 0; i < sampleCount; ++i) {
            readSensor();

            for (int j = 0; j < 7; ++j) {
                sum[j] += sensorValue[j];
            }

            //delay(interval);
        }

        for (int i = 0; i < 7; ++i) {
            sensorValue_average[i] = sum[i] / double(sampleCount);
        }
    }

public:
    static void begin() {
        //Wire.begin();
        //Wire.setClock(400000);

        //Wire.beginTransmission(0x68);
        //Wire.write(0x6b);
        //Wire.write(0x0);
        //Wire.endTransmission(true);

        setSensorValue_average();
    }

    static void trace() {
        //static long int previousTime = micros();
        static time_t previousTime = time(NULL);
        static time_t currentTime;
        static time_t elapsedTime;

        readSensor();

        //currentTime = micros();
        currentTime = time(NULL);
        elapsedTime = currentTime - previousTime;

        for (int i = 4; i < 7; ++i) {
            angle[i - 4] += (sensorValue[i] - sensorValue_average[i]) / 131 * elapsedTime / 1000000;
        }

        previousTime = currentTime;
    }

    static void printDescription() {
        //Serial.println();

        //Serial.print("Accel: [");
        //if (sensorValue[0] >= 0) Serial.print(' ');
        //Serial.print(sensorValue[0]);
        //Serial.print(", ");
        //if (sensorValue[1] >= 0) Serial.print(' ');
        //Serial.print(sensorValue[1]);
        //Serial.print(", ");
        //if (sensorValue[2] >= 0) Serial.print(' ');
        //Serial.print(sensorValue[2]);
        //Serial.print("]");

        //Serial.println();

        //Serial.print("Temp: ");
        //if (sensorValue[3] >= 0) Serial.print(' ');
        //Serial.print(sensorValue[3]);

        //Serial.println();

        //Serial.print("Angle: [");
        //if (angle[0] >= 0) Serial.print(' ');
        //Serial.print(angle[0]);
        //Serial.print(", ");
        //if (angle[1] >= 0) Serial.print(' ');
        //Serial.print(angle[1]);
        //Serial.print(", ");
        //if (angle[2] >= 0) Serial.print(' ');
        //Serial.print(angle[2]);
        //Serial.print("]");

        //Serial.println();

        printf("Accel: [%8.2f, %8.2f, %8.2f] \n",
            sensorValue[0] - sensorValue_average[0],
            sensorValue[1] - sensorValue_average[0],
            sensorValue[2] - sensorValue_average[0]);
        printf("Temp: %8.2f \n",
            sensorValue[3] - sensorValue_average[0]);
        printf("Angle: [%8.2f, %8.2f, %8.2f] \n\n", angle[0], angle[1], angle[2]);
    }
};

int MPU::sensorValue[7];
double MPU::sensorValue_average[7];

double MPU::angle[3] = { 0 };



// function
inline void serialBegin() {
    //Serial.begin(115200);
}

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



// main
int main(int argc, char** argv) {
    setup();

    while (true) {
        loop();
    }

    return 0;
}