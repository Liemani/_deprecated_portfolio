// 입력을 받아오는 것보다 처리 속도가 더 빠르다 그래서 Serial.available() > 0 이 되기 전에 루프를 반복한다!

void setup() {
  Serial.begin(115200);

  Serial.print('\n');
  Serial.print('\n');
  Serial.print("Serial Test !!\n");
  Serial.print("echo >> ");
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();
    Serial.write(ch);

    if (ch == '\n') {
      Serial.print("echo >> ");
    }
  }
}
