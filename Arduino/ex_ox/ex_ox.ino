//********************************************
// char* title = "ex_ox"
// made by Lieman at 2020.06.10
//
// description:
//	Serial example
//********************************************





#define LED0 13

void setup() {
  pinMode(LED0, OUTPUT);
  
  Serial.begin(115200);

  Serial.print('\n');
  Serial.print('\n');
  Serial.print("Serial Test !!\n");
  Serial.print("echo >> ");
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();
    Serial.print(ch);

    if (ch == 'O') {
      digitalWrite(LED0, HIGH);
    } else if (ch == 'X') {
      digitalWrite(LED0, LOW);
    } else if (ch == '\n') {
      Serial.print("echo >> ");
    }
  }
}
