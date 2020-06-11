//********************************************
// char* title = "ex_cds_01"
// made by Lieman at 2020.06.11
//
// description:
//  cds example
//********************************************





int pinGnd = A2;
int pinVcc = A1;
int pinCds = A0;

void setup() {
    Serial.begin(115200);
    
    pinMode(pinGnd, OUTPUT);
    pinMode(pinVcc, OUTPUT);
    pinMode(pinCds, INPUT);

    digitalWrite(pinGnd, LOW);
    digitalWrite(pinVcc, HIGH);
}

void loop() {
    int adcData = analogRead(pinCds);
    Serial.print("CDS: ");
    Serial.println(adcData);
    delay(500);
}
