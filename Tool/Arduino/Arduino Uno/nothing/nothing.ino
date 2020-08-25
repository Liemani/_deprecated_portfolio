//********************************************
// char* title = "nothing"
// made by Lieman at 2020.06.10
//
// description:
//	make machine rest
//  and test things
//********************************************





void setup() {
    Serial.begin(115200);
    Serial.print(sizeof(uint8_t));
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000000);
}
