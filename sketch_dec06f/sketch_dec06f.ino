#include <Servo.h>

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
}
int i ;
void loop() {
  // put your main code here, to run repeatedly:
  for (i = 0; i < 120; ++i){
    myservo.write(i);
    delay(15);
  }
  if(i == 120){
    for(i = 120 ; i>0; --i){
      myservo.write(i);
    delay(15);  
    }
  }
  delay(1000);
}
