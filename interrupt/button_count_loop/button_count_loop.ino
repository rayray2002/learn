int count = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(3) == HIGH) {
    count++;
    delay(500);
  }
  Serial.println(count);
}
