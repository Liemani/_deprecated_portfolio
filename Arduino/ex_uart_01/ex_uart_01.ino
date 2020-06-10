void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  for (char i = 0; i < 127; ++i) {
    Serial.println(i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
