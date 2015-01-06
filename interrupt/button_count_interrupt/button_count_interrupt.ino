int count = 0;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, counting, CHANGE);
}
void loop() {
  Serial.println(count);
  delay(1000);
}

void counting() {
  count++;
}
