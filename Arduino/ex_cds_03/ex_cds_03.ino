//********************************************
// char* title = "ex_cds_03"
// made by Lieman at 2020.06.11
//
// description:
//  cds example
//********************************************





#define LED_PIN 13
#define LOOP_TIME 23

int pinGnd = A2;
int pinVcc = A1;
int pinCds = A0;

int adcData;
int brightness;

void setup() {
    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinCds, INPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);
    digitalWrite(LED_PIN, LOW);
}

void loop() {
    adcData = analogRead(pinCds);
    
    digitalWrite(LED_PIN, HIGH);
    
    brightness = adcData / (1024 / LOOP_TIME + 1);
    
    delay(brightness);
    
    digitalWrite(LED_PIN, LOW);
    
    delay(LOOP_TIME - brightness);
}
