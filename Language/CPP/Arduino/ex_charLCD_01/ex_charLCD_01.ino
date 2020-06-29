//********************************************
// char* title = "ex_charLCD_01"
// made by Lieman at 2020.06.11
//
// description:
//  character lcd example
//********************************************





#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);
char ch;
uint8_t cursorRow = 0;
uint8_t cursorColumn = 0;


void setup() {
    Serial.begin(115200);
    
    lcd.begin(16, 2);
}

void loop() {
    if (Serial.available() > 0) {
        ch = Serial.read();

        if (ch != '\n') {
            lcd.print(ch);
            
            // move cursor to available next place
            if(!(++cursorColumn %= 16)) {
                ++cursorRow %= 2;
                lcd.setCursor(cursorColumn, cursorRow);
            }
        }
    }
}
