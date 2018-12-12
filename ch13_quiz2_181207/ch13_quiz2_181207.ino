#include <Servo.h>

Servo myservo;



void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  pinMode(8, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int push = digitalRead(8);
  int val = analogRead(A0);
  int rad = map(val, 0, 1023, 0, 170);
  if(push == HIGH){
    myservo.write(rad);
    delay(15);  
  }
}
