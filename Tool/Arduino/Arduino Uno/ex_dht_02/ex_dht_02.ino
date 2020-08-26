//********************************************
// char* title = "ex_dht_02"
// made by Lieman at 2020.06.11
//
// description:
//  dht example
//********************************************





#include <LiquidCrystal.h>
#include "DHT.h"

#define VCC A2
#define DHTPIN A1
#define GND A0

#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);
char ch;
uint8_t cursorRow = 0;
uint8_t cursorColumn = 0;

char displayBuffer[16 * 2];

void setup() {
    Serial.begin(115200);
  
    pinMode(VCC, OUTPUT);
    pinMode(GND, OUTPUT);

    digitalWrite(VCC, HIGH);
    digitalWrite(GND, LOW);
    
    lcd.begin(16, 2);
    
    dht.begin();
}

void loop() {
    // Wait a few seconds between measurements.
    delay(2000);
    
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = dht.readTemperature(true);
    
    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        return;
    }
    
    // Compute heat index in Fahrenheit (the default)
    float hif = dht.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    lcd.print(t);
    lcd.setCursor(cursorColumn, cursorRow);
    
//    sprintf(displayBuffer, "TEM: %f\'", t);
//
//    for (int i = 0; i < 32; ++i) {
//        if (displayBuffer[i] == '\0') {
//            lcd.print(' ');
//        } else {
//            lcd.print(displayBuffer[i]);
//        }
//        
//        if(!(++cursorColumn %= 16)) {
//            ++cursorRow %= 2;
//            lcd.setCursor(cursorColumn, cursorRow);
//        }
//    }
    
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.print(F("°C "));
    Serial.print(hif);
    Serial.println(F("°F"));
}
