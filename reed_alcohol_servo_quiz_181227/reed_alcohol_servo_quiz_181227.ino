#include <Servo.h>

Servo myservo;

int pin_sensor = 3;
int pin_led = 7;
int pin_alcohol = A0;
int pin_button = 8;
int flag = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_sensor, INPUT);
  pinMode(pin_button, INPUT);
  myservo.attach(9);
}

void loop() {
  int reedSW = digitalRead(pin_sensor);
  int alcohol;
  int result = map(alcohol, 0, 1023, 0, 255);
  int value = digitalRead(8);


  if(reedSW == LOW) {
    if(flag == 1){
      digitalWrite(pin_led, HIGH);
      myservo.write(0);  
    }else{
      digitalWrite(pin_led, LOW);
      myservo.write(90);
    }
  }else{
    digitalWrite(pin_led, LOW);
    myservo.write(90);
  }
  
  if(value == HIGH){
    alcohol = analogRead(pin_alcohol);
  }
  if(alcohol <= 300){
    flag = 1;
  }else{
    flag = 0;
  }
  Serial.print("reed : ");
  Serial.println(reedSW);
  Serial.print("alcohol : ");
  Serial.println(alcohol);
  delay(1000); 
}
