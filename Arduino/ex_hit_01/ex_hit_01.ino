//********************************************
// char* title = "ex_hit_01"
// made by Lieman at 2020.06.10
//
// description:
//	hit sensor example
//  use interrupt
//********************************************





#define GND 4
#define VCC 3
#define SIGNAL 2

int count = 0;

void setup() {
    Serial.begin(115200);
    
    pinMode(GND, OUTPUT);
    pinMode(VCC, OUTPUT);
    pinMode(SIGNAL, INPUT);

    digitalWrite(GND, LOW);
    digitalWrite(VCC, HIGH);

    attachInterrupt(0, hitISR, RISING);
}

void loop() {
    Serial.print("Hit: ");
    Serial.print(count);
    Serial.print('\n');
    
    delay(500);
}

void hitISR() {
    ++count;
}
