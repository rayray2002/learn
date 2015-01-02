#include <Servo.h> 
 
Servo spin, claw, x, y;

int y_low = 180;
int y_high = 180;
int claw_open = 0;
int claw_close = 30;

void setup() { 
  spin.attach(7);
  claw.attach(8);
  x.attach(9);
  y.attach(10);
} 
 
void loop() {
  for (int i = 0; i<190; i++) {
    spin.write(i);
    delay(30);
  }
  y.write(y_low);//low
  for (int i = 0; i<3; i++) {
    claw.write(claw_close);//close
    delay(200);
    claw.write(claw_open);//open
    delay(200);
  }
  delay(3000);
  claw.write(claw_close);//close
  delay(100);
  y.write(y_high);//high
  delay(100);
  for(int i = 180; i>1; i--) {
    spin.write(i);
    delay(30);
  }
  y.write(y_low);//low
  delay(100);
  claw.write(claw_open);//open
  delay(200);
  y.write(y_high);//high
  delay(100);
} 
