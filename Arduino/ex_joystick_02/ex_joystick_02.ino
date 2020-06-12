//********************************************
// char* title = "ex_joystick_02"
// made by Lieman at 2020.06.12
//
// description:
//  joystick example
//  also use 6 digit FND
//  up, down makes the cursor number up and down
//  left, right move the cursor
//  click makes the number on cursor 0
//
// caution:
//  if you use Serial.begin, 5th and 6th fnd will turned off!!
// global constatant
//********************************************





// global constatant
#define GND_PIN A0
#define VCC_PIN A1
#define VRX_PIN A2
#define VRY_PIN A3
#define SW_PIN A4

#define DURATION 2
#define TIME_INTERVAL 1000

const int fndDataPinArray[8] = {13, 12, 11, 10, 9, 8, 7, 6};
const int fndSelPinArray[6] = {5, 4, 3, 2, 1, 0};

const uint8_t fndHexDigitArray[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
const uint8_t fndBlank = 0x00;


// global variable
uint8_t fndBuffer[6];   // number character! (-1 ~ 9)

uint8_t selection = 0;

unsigned long preTime;
unsigned long curTime;

unsigned long lockStartTime = 0;
unsigned long lockedTime;
boolean isUpdateLock = false;

int i = 0;
int j = 0;

int count = 0;

int fndCursor = 0;

int curVRX;
int curVRY;
int preVRX = 0;
int preVRY = 0;



// function
void lockUpdate(unsigned long duration) {
    lockStartTime = curTime;
    lockedTime = duration;
    isUpdateLock = true;
}

void updateFrame() {
    curVRX = map(analogRead(VRX_PIN), 0, 1023, -1, 2);
    curVRY = map(analogRead(VRY_PIN), 0, 1023, -1, 2);
    
    if (curVRX != preVRX) {
        if (curVRX == 1) {
            ++fndCursor %= 6;
        } else if (curVRX == -1) {
            --fndCursor;
            if (fndCursor == -1) {
                fndCursor = 5;
            }
        }
    }
    
    if (curVRY != preVRY) {
        if (curVRY == -1) {
            ++fndBuffer[fndCursor];
            if (fndBuffer[fndCursor] == ('0' + 10)) {
                fndBuffer[fndCursor] = '0';
            }
        } else if (curVRY == 1) {
            --fndBuffer[fndCursor];
            if (fndBuffer[fndCursor] == ('0' - 1)) {
                fndBuffer[fndCursor] = '9';
            }
        }
    }
    
    if (!digitalRead(SW_PIN)) {
        fndBuffer[fndCursor] = '0';
    }

    preVRX = curVRX;
    preVRY = curVRY;
}

void renderFrame() {
    for (int i = 0; i < 8; ++i) {
        digitalWrite(fndDataPinArray[i], (fndHexDigitArray[fndBuffer[selection] - '0'] >> i) & 0x01);
    }

    if (selection != fndCursor || (curTime / 150) % 4 != 3) {
        digitalWrite(fndSelPinArray[selection], LOW);
    }
    
    delay(DURATION);
    digitalWrite(fndSelPinArray[selection], HIGH);

    ++selection %= 6;
}



// main function
void setup() {
    for (int i = 0; i < 8; ++i) {
        pinMode(fndDataPinArray[i], OUTPUT);

        digitalWrite(fndDataPinArray[i], HIGH);
    }

    for (int i = 0; i < 6; ++i) {
        pinMode(fndSelPinArray[i], OUTPUT);
        
        digitalWrite(fndSelPinArray[i], HIGH);
    }

    for (int i = 0; i < 6; ++i) {
        fndBuffer[i] = '0';
    }
    
    pinMode(GND_PIN, OUTPUT);
    pinMode(VCC_PIN, OUTPUT);
    pinMode(VRX_PIN, INPUT);
    pinMode(VRY_PIN, INPUT);
    pinMode(SW_PIN, INPUT_PULLUP);

    digitalWrite(GND_PIN, LOW);
    digitalWrite(VCC_PIN, HIGH);
}

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
