#include <Servo.h> 
 
Servo spin, claw, x, y;

int y_low = 20;
int y_high = 10;
int claw_open = 160;
int claw_close = 180;

void setup() { 
  spin.attach(7);
  claw.attach(8);
  x.attach(9);
  y.attach(10);
} 
 
void loop() {
  for (int i = 0; i<190; i++) {
    spin.write(i);
    delay(50);
  }
  y.write(y_low);//low
  delay(100);
  x.write(0);//mid
  delay(100);
  for (int i = 0; i<5; i++) {
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
  for(int i = 180; i>0; i--) {
    spin.write(i);
    delay(50);
  }
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
