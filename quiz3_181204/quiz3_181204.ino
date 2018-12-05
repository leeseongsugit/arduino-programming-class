//void setup() {
//  // put your setup code here, to run once:
//  pinMode(2, INPUT);
//  pinMode(4, INPUT);
//  pinMode(7, INPUT);
//
//  pinMode(8, OUTPUT);
//  pinMode(12, OUTPUT);
//  pinMode(13, OUTPUT);
//
//  Serial.begin(9600);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  int red = digitalRead(7);
//  int yel = digitalRead(4);
//  int gre = digitalRead(2);
//
//  Serial.print("r : ");
//  Serial.println(red);
//  Serial.print("y : ");
//  Serial.println(yel);
//  Serial.print("g : ");
//  Serial.println(gre);
//  delay(100);
//  
//  if(red == HIGH){
//    digitalWrite(13, HIGH);
//  }else{
//    digitalWrite(13, LOW);
//  }
//  if(yel == HIGH){
//    digitalWrite(12, HIGH);
//  }else{
//    digitalWrite(12, LOW);
//  }
//  if(gre == HIGH){
//    digitalWrite(8, HIGH);
//  }else{
//    digitalWrite(8, LOW);
//  }
//}

int red_button;
int yellow_button;
int green_button;

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);  // red led
  pinMode(12, OUTPUT);  // yellow led
  pinMode(8, OUTPUT);   // green led
  pinMode(7, INPUT);    // red led button
  pinMode(4, INPUT);    // yellow led button
  pinMode(2, INPUT);    // green led button

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  red_button = digitalRead(7);
  yellow_button = digitalRead(4);
  green_button = digitalRead(2);

  Serial.print("r : ");
  Serial.println(red_button);
  Serial.print("y : ");
  Serial.println(yellow_button);
  Serial.print("g : ");
  Serial.println(green_button);

  delay(100);
  
  if(red_button == HIGH) {
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(8, LOW);
  }

  if(yellow_button == HIGH) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(8, LOW);
  }

  if(green_button == HIGH) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(8, HIGH);
  }
}
