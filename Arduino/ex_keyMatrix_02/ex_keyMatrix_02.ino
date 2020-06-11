int rowPinArray[] = {13, 12, 11, 10};
int columnPinArray[] = {9, 8, 7, 6};

uint16_t switchData = 0;

int row;
int column;

char serialBuffer[4][4];

void setup() {
    Serial.begin(2000000);

    randomSeed(analogRead(0));
    
    for (row = 0; row < 4; ++row) {
        pinMode(rowPinArray[row], OUTPUT);
        
        digitalWrite(rowPinArray[row], LOW);
    }
    
    for (column = 0; column < 4; ++column) {
        pinMode(columnPinArray[column], INPUT);
    }
}

void loop() {
    for (row = 0; row < 4; ++row) {
        digitalWrite(rowPinArray[row], HIGH);

        for (column = 0; column < 4; ++column) {
            switchData <<= 1;
            switchData |= digitalRead(columnPinArray[column]);
        }
        
        digitalWrite(rowPinArray[row], LOW);
    }

    for (row = 0; row < 4; ++row) {
        for (column = 0; column < 4; ++column) {
            if (0x01 & switchData >> (15 - row * 4 - column)) {
                serialBuffer[row][column] = 'O';
            } else {
                serialBuffer[row][column] = 'X';
            }
        }
    }
    
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print('\n');
    Serial.print("----\n");
    for (row = 0; row < 4; ++row) {
        for (column = 0; column < 4; ++column) {
            Serial.print(serialBuffer[row][column]);
        }

        Serial.print('\n');
    }

    delay(10);
}
