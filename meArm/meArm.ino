#include <Servo.h> 
 
Servo spin, claw, y;

int y_low = 50;
int y_high = 160;
int claw_open = 0;
int claw_close = 30;

void setup() { 
  spin.attach(7);
  claw.attach(8);
  y.attach(10);
}

void move_servo(Servo s, int deg) {
  int current = s.read();
  int diff = deg - current;
  byte step = diff / abs(diff);
  while (current != deg) {
      s.write(current+step);
      delay(20);
      current = s.read();
  }
}
void loop() {
  spin.write(90);
  y.write(60);
  while(1) {
    move_servo(spin, 90);
    y.write(60);
    move_servo(y, 120);
    for(int i = 60; i<150; i++) {
      y.write(i);
      delay(30);
    }
  
    for (int i = 0; i<3; i++) {
      claw.write(claw_close);//close
      delay(200);
      claw.write(claw_open);//open
      delay(200);
    }
    delay(2000);
  
    claw.write(claw_close);//close
    delay(100);
  
    for(int i = 90; i>1; i--) {
      spin.write(i);
      delay(30);
    }
  
    for(int i = 150; i>60; i--) {
      y.write(i);
      delay(30);
    }
  
    claw.write(claw_open);//open
    delay(500);
  }
}

