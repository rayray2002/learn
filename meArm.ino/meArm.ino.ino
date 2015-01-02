#include <Servo.h> 
 
Servo spin, claw, x, y;


void setup() { 
  spin.attach(7);
  claw.attach(8);
  x.attach(9);
  y.attach(10);
} 
 
void loop() {
  spin.write(180);
  y.write();
  x.write();
  for (int i; i<4; i++) {
    claw.write(45);
    delay(200);
    claw.write(135);
    delay(200);
  }
  delay(1000);
  claw.write();
  y.write();
  spin.write(0);
  y.write();
  claw.write();
} 
