int pin_in1 = 5;
int pin_in2 = 6;
int pin_speed = 3;

void setup() {
  pinMode(pin_in1, OUTPUT);
  pinMode(pin_in2, OUTPUT);
  pinMode(pin_speed, OUTPUT);
  Serial.begin(9600);
 }

void loop() {
  // 시계방향으로 회전
  digitalWrite(pin_in1, HIGH);
  digitalWrite(pin_in2, LOW);

  analogWrite(pin_speed, 50);
  delay(3000);

  

  analogWrite(pin_speed, 150);
  delay(3000);
  
  analogWrite(pin_speed, 200);
  delay(3000);

  analogWrite(pin_speed, 255);
  delay(3000);
  
}
