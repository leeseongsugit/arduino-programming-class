int pin_in1 = 5;
int pin_in2 = 6;
int pin_speed = 3;

int pin_off = 8;
int pin_slow = 12;
int pin_fast = 13;

int flag = 0;

void setup() {
  pinMode(pin_in1, OUTPUT);
  pinMode(pin_in2, OUTPUT);
  pinMode(pin_speed, OUTPUT);
  pinMode(pin_off, INPUT);
  pinMode(pin_slow, INPUT);
  pinMode(pin_fast, INPUT);
  Serial.begin(9600);
 }

void loop() {
  // 시계방향으로 회전
  int value = digitalRead(pin_off);
  int value2 = digitalRead(pin_slow);
  int value3 = digitalRead(pin_fast);

  
  Serial.print("value : ");
  Serial.println(value);
  Serial.print("value2 : ");
  Serial.println(value2);
  Serial.print("value3 : ");
  Serial.println(value3);
  
  if(value2 == HIGH){
    flag = 1;
  }else if(value3 == HIGH){
    flag = 2;
  }else{
    flag = 0;
  }
  if(flag == 0){
    digitalWrite(pin_in1, LOW);
    digitalWrite(pin_in2, LOW);
    analogWrite(pin_speed, 0);
    delay(3000);
  }else if(flag == 1){
    digitalWrite(pin_in1, HIGH);
    digitalWrite(pin_in2, LOW);
    analogWrite(pin_speed, 20);
    delay(3000);
  }else{
    digitalWrite(pin_in1, HIGH);
    digitalWrite(pin_in2, LOW);
    analogWrite(pin_speed, 150);
    delay(3000);
  }

}
