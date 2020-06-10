// constant
#define switchLedCount 4

const int ledPinArray[] = {13, 12, 11, 10};
const int switchPinArray[] = {9, 8, 7, 6};



// class implementation
class Led {
    public:
        int pin;
        boolean on;
        unsigned long onTime;
        
        boolean isOn() {
            return digitalRead(pin);
        }

        void set(boolean value) {
            digitalWrite(pin, value);
        }
};

class Switch {
    public:
        int pin;
        boolean previous;

        boolean isOn() {
            return digitalRead(pin);
        }
};



// global variable
Led ledArray[4];
Switch switchArray[4];

unsigned long preTime;
unsigned long timeInterval;
unsigned long curTime;

boolean switchCurVal;



// main function
void setup() {
    for (int i = 0; i < switchLedCount; ++i) {
        // set Pin
        ledArray[i].pin = ledPinArray[i];
        switchArray[i].pin = switchPinArray[i];

        // set mode
        pinMode(ledArray[i].pin, OUTPUT);
        pinMode(switchArray[i].pin, INPUT);

        // set state
        ledArray[i].set(LOW);
        switchArray[i].previous = LOW;
    }
}

void loop() {
    curTime = millis();
    timeInterval = curTime - preTime;
    
    for (int i = 0; i < switchLedCount; ++i) {
        switchCurVal = switchArray[i].isOn();
        
        if (switchCurVal == true && switchArray[i].previous == false) {
            ledArray[i].on = !ledArray[i].on;
            ledArray[i].set(ledArray[i].on);
            ledArray[i].onTime = curTime;
        }
        
        if (ledArray[i].on) {
            if (((curTime - ledArray[i].onTime) / 300) % 2) {
                ledArray[i].set(HIGH);
            } else {
                ledArray[i].set(LOW);
            }
            ledArray[i].set(!ledArray[i].isOn());
        }
        
        switchArray[i].previous = switchCurVal;
    }

    if (timeInterval < 1000 / 60) {
        delay(1000 / 60 - timeInterval);
    }

    preTime = curTime;
}
