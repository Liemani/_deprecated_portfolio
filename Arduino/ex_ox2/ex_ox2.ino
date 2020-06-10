#include <string.h>
#define BUFFER_MAX 10

#define LED0 13

#define ON_MESSAGE "led_on"
#define OFF_MESSAGE "led_off"

char buffer[BUFFER_MAX];
int i = 0;

void setup() {
    pinMode(LED0, OUTPUT);
  
    Serial.begin(115200);

    Serial.print('\n');
    Serial.print('\n');
    Serial.print("Serial Test !!\n");
    Serial.print("echo >> ");
}

void loop() {
    if (Serial.available() == 0) return;
  
    char ch = Serial.read();
    Serial.print(ch);

    if (ch != '\n') {
        buffer[i] = ch;
        ++i;
    } else {
        i = 0;
        buffer[i] = '\0';
        if (!strcmp(buffer, ON_MESSAGE)) {
            digitalWrite(LED0, HIGH);
        } else if (!strcmp(buffer, OFF_MESSAGE)) {
            digitalWrite(LED0, LOW);
        }
        Serial.print("echo >> ");
    }
}
