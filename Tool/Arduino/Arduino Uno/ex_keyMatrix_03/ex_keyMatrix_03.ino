//********************************************
// char* title = "ex_keyMatrix_03"
// made by Lieman at 2020.06.11
//
// description:
//	press switch located at 'O' in the display!
//
// caution:
//  didn't use rising or falling pressure
//  if you play this game using arduino's default serial monitor,
//  you need to clear the debug screen own yourself periodically
//********************************************





#define START_MINE_INTERVAL 500
#define MINE_INTERVAL_REDUCTION -5

int rowPinArray[] = {13, 12, 11, 10};
int columnPinArray[] = {9, 8, 7, 6};

uint16_t switchData = 0;

int row;
int column;

char serialBuffer[4][4];

unsigned long curTime;
unsigned long preTime;

boolean shouldGameEnd = false;

uint8_t randomNumber;

unsigned long mineTimeInterval = START_MINE_INTERVAL;
unsigned long nextMineTime = START_MINE_INTERVAL;

void setup() {
    Serial.begin(1000000);

    randomSeed(analogRead(0));
    
    for (row = 0; row < 4; ++row) {
        pinMode(rowPinArray[row], OUTPUT);
        
        digitalWrite(rowPinArray[row], LOW);
    }
    
    for (column = 0; column < 4; ++column) {
        pinMode(columnPinArray[column], INPUT);
    }

    for (row = 0; row < 4; ++row) {
        for (column = 0; column < 4; ++column) {
            serialBuffer[row][column] = 'X';
        }
    }
}

void loop() {
    curTime = millis();

    // make a mine
    if (nextMineTime < preTime) {
        randomNumber = random(16);
        while (serialBuffer[randomNumber / 4][randomNumber % 4] == 'O') {
            ++randomNumber %= 16;
        }
        serialBuffer[randomNumber / 4][randomNumber % 4] = 'O';
        mineTimeInterval += MINE_INTERVAL_REDUCTION;
        nextMineTime += mineTimeInterval;
    }

    // read pressed switch
    for (row = 0; row < 4; ++row) {
        digitalWrite(rowPinArray[row], HIGH);

        for (column = 0; column < 4; ++column) {
            switchData <<= 1;
            switchData |= digitalRead(columnPinArray[column]);
        }
        
        digitalWrite(rowPinArray[row], LOW);
    }

    // action for pressed button
    shouldGameEnd = true;
    for (row = 0; row < 4; ++row) {
        for (column = 0; column < 4; ++column) {
            if ((switchData >> (15 - row * 4 - column)) & 0x01) {
                if (serialBuffer[row][column] == 'O') {
                    serialBuffer[row][column] = 'X';
                }
            }
        }

        if (serialBuffer[row][column] == 'X') {
            shouldGameEnd = false;
        }
    }

    // display data
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    
    for (row = 0; row < 4; ++row) {
        for (column = 0; column < 4; ++column) {
            Serial.print(serialBuffer[row][column]);
        }

        Serial.print('\n');
    }

    Serial.print('\n');
    Serial.print("Your score: ");
    Serial.print(curTime / 1000);
    Serial.print('s');
    Serial.print('\n');

    // print game end
    if (shouldGameEnd) {
        Serial.print('\n');
        Serial.print('\n');
        Serial.print("Game End!!");
        delay(1000000000);
    }

    preTime = curTime;

    delay(10);
}
