// global constatant
#define DURATION 2
#define TIME_INTERVAL 500

const int fndDataPinArray[8] = {13, 12, 11, 10, 9, 8, 7, 6};
const int fndSelPinArray[6] = {5, 4, 3, 2, 1, 0};

const uint8_t fndHexDigitArray[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};



// global variable
uint8_t fndBuffer[6];

uint8_t selection = 0;

unsigned long preTime;
unsigned long curTime;

unsigned long lockStartTime = 0;
unsigned long lockedTime;
boolean isUpdateLock = false;

int i = 0;
int j = 0;



// function
void lockUpdate(unsigned long duration) {
    lockStartTime = curTime;
    lockedTime = duration;
    isUpdateLock = true;
}

void updateFrame() {
    for (int k = 0; k < 6; ++k) {
        fndBuffer[k] = 0x00;
    }
    
    fndBuffer[i] = fndHexDigitArray[j];

    if (!(++j %= 16))
        ++i %= 6;
        
    lockUpdate(TIME_INTERVAL);
}

void renderFrame() {
    for (int i = 0; i < 6; ++i) {
        digitalWrite(fndSelPinArray[i], HIGH);
    }

    digitalWrite(fndSelPinArray[selection], LOW);

    for (int i = 0; i < 8; ++i) {
        digitalWrite(fndDataPinArray[i], (fndBuffer[selection] >> i) & 0x01);
    }

    delay(DURATION);

    for (int i = 0; i < 8; ++i) {
        digitalWrite(fndDataPinArray[i], LOW);
    }

    ++selection %= 6;
}



// main function
void setup() {
    for (int i = 0; i < 8; ++i) {
        pinMode(fndDataPinArray[i], OUTPUT);

        digitalWrite(fndDataPinArray[i], LOW);
    }

    for (int i = 0; i < 6; ++i) {
        pinMode(fndSelPinArray[i], OUTPUT);
        
        digitalWrite(fndSelPinArray[i], HIGH);
    }

    for (int i = 0; i < 6; ++i) {
        fndBuffer[i] = fndHexDigitArray[i + 5];
    }
}

// fps는 나중에 신경쓰고 일단 출력에 2ms를 사용하도록 만들자
void loop() {
    curTime = millis();

    if (isUpdateLock && curTime - lockStartTime > lockedTime) {
        isUpdateLock = false;
    }

    if (!isUpdateLock)
        updateFrame();
    
    renderFrame();

    preTime = curTime;
}
