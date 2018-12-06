void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  pinMode(3, INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = digitalRead(8);

  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);

  long duration = pulseIn(3, HIGH);

  if(duration == 0){
    return;
  }

  long distance = duration/58.2;
  Serial.println(distance);
  Serial.print("r : ");
  Serial.println(value);
  
  if(value == HIGH){  
    if(distance < 10) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      Serial.print("r : ");
      Serial.println(value);
      Serial.println(distance);
    }else{
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
            Serial.println(distance);
    }
    delay(100);  
  }else{
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  
}
