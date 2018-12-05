int a;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i <= 8; i++){
    Serial.println(i);
    analogWrite(9, i*31);
    delay(100);
  }
  for(int i = 8; i >= 0; i--){
    analogWrite(9, i*31);
    delay(100);
  }
  
 

}
