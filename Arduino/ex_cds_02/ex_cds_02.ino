//********************************************
// char* title = "ex_cds_02"
// made by Lieman at 2020.06.11
//
// description:
//  cds example
//********************************************





#define LED_PIN 13

int pinGnd = A2;
int pinVcc = A1;
int pinCds = A0;

void setup() {
    Serial.begin(115200);
    
    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinCds, INPUT);
    pinMode(LED_PIN, OUTPUT);

    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);
    digitalWrite(LED_PIN, LOW);
}

void loop() {
    int adcData = analogRead(pinCds);
    Serial.print("CDS: ");
    digitalWrite(LED_PIN, adcData / (1024 / 2));
    delay(500);
}
