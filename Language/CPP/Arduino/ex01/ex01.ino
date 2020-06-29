//********************************************
// char* title = "ex01"
// made by Lieman at 2020.06.10
//
// description:
//	led example
//********************************************





const int ledArray[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int i = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 8; ++i) {
    pinMode(ledArray[i], OUTPUT); 
  }

  digitalWrite(ledArray[0], HIGH);
  digitalWrite(ledArray[4], HIGH);
  
  delay(100);
}

void loop() {
  for (; i < 3; ++i) {
    digitalWrite(ledArray[i + 1], HIGH);
    digitalWrite(ledArray[i], LOW);
    
    digitalWrite(ledArray[i + 5], HIGH);
    digitalWrite(ledArray[i + 4], LOW);
    
    delay(100);
  }

  for (; i > 0; --i) {
    digitalWrite(ledArray[i - 1], HIGH);
    digitalWrite(ledArray[i], LOW);
    
    digitalWrite(ledArray[i + 3], HIGH);
    digitalWrite(ledArray[i + 4], LOW);
    
    delay(100);
  }
}
