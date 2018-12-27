#include <Servo.h>

Servo myservo;

int pin_sensor = 3;
int pin_led = 7;

void setup() {
  Serial.begin(9600);
  pinMode(pin_led, OUTPUT);
  pinMode(pin_sensor, INPUT);
  myservo.attach(9);
}

void loop() {
  int reedSW = digitalRead(pin_sensor);

  if(reedSW == LOW) {
    digitalWrite(pin_led, HIGH);
    myservo.write(0);

  } else {
    digitalWrite(pin_led, LOW);
    myservo.write(90);
  }
  Serial.print("reed : ");
  Serial.println(reedSW);
  delay(1000); 
}
