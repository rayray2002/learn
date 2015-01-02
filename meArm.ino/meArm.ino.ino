#include <Servo.h> 
 
Servo spin, claw, x, y;

int y_low = 0;
int y_high = 0;
int claw_open = 45;
int claw_close = 135;

void setup() { 
  spin.attach(7);
  claw.attach(8);
  x.attach(9);
  y.attach(10);
} 
 
void loop() {
  spin.write(180);
  delay(100);
  y.write(y_low);//low
  delay(100);
  x.write(0);//mid
  delay(100);
  for (int i; i<4; i++) {
    claw.write(claw_close);//close
    delay(200);
    claw.write(claw_open);//open
    delay(200);
  }
  delay(1000);
  claw.write(claw_close);//close
  delay(100);
  y.write(y_high);//high
  delay(100);
  spin.write(0);
  delay(100);
  y.write(y_low);//low
  delay(100);
  claw.write(claw_open);//open
  delay(100);
  y.write(y_high);//high
  delay(100);
  spin.write(180);
  delay(100);
  y.write(y_low);//low
  delay(100);
} 
