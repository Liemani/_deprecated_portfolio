const int LED = 17;
int 

void setup() {
    // put your setup code here, to run once:
    pinMode(LED, OUTPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
    
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            digitalWrite(LED, LOW);
            delay(i);
            digitalWrite(LED, HIGH);
            delay(10 - i);
        }
    }

    for (int i = 10; i > 0; --i) {
        for (int j = 0; j < 10; ++j) {
            digitalWrite(LED, LOW);
            delay(i);
            digitalWrite(LED, HIGH);
            delay(10 - i);
        }
    }
}
