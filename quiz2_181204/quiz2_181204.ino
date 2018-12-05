
void setup() {
  // put your setup code here, to run once:
//  pinMode(red, OUTPUT);
//  pinMode(yel, OUTPUT);
//  pinMode(gre, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i = 0; i <= 10; i++){
    analogWrite(11, i*25);
    delay(100);
  }
  for(int i = 10; i >= 0; i--){
    analogWrite(11, i*25);
    delay(100);
  }

  for(int i = 0; i <= 10; i++){
    analogWrite(6, i*25);
    delay(100);
  }
  for(int i = 10; i >= 0; i--){
    analogWrite(6, i*25);
    delay(100);
  }

  for(int i = 0; i <= 10; i++){
    analogWrite(5, i*25);
    delay(100);
  }
  for(int i = 10; i >= 0; i--){
    analogWrite(5, i*25);
    delay(100);
  }
  
}
