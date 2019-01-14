int sound_pin = A0;
int led1_pin = 11;
int led2_pin = 10;
int led3_pin = 9;
int init_btn = 8;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(init_btn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  
  if(sound_value >= 1023){
    ++count;
  }
  if(count < 5){
    analogWrite(9, 255);
    analogWrite(10, 0);
    analogWrite(11, 0);
  }else if(count < 10){
    analogWrite(9, 0);
    analogWrite(10, 255);
    analogWrite(11, 0);
  }else if(count < 20){
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 255);
  }else{
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);
  }
  
  Serial.print("sound value : " );
  Serial.println(sound_value);

  Serial.print("count : " );
  Serial.println(count);
  delay(100);
  if(digitalRead(init_btn) == HIGH){
    count = 0;
  }
}
