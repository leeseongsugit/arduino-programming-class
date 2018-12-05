int melody[] = {262,294,330,349,392,440,494,523};
int sheet[] = {4,4,5,5,4,4,2,4,4,2,2,1,4,4,5,5,4,4,2,4,2,1,2,0}
void setup() {
  // put your setup code here, to run once:
//  for(int i = 0; i < 8; i++){
//    tone(8, melody[i], 250);
//    delay(400);
//    noTone(8);
//  }
  for(int i = 0; i < 6; i++){
    tone(8, melody[sheet[i]], 150);
    delay(250);
    noTone(8);   
  }
  tone(8, melody[6], 300);
  delay(450);
  noTone(8);
  
  for(int i = 7; i < 11; i++){
    tone(8, melody[sheet[i]], 150);
    delay(200);
    noTone(8);   
  }
  tone(8, melody[11], 600);
  delay(750);
  noTone(8);

  for(int i = 12; i < 18; i++){
    tone(8, melody[sheet[i]], 150);
    delay(250);
    noTone(8);   
  }
  tone(8, melody[18], 300);
  delay(450);
  noTone(8);
  
  for(int i = 19; i < 23; i++){
    tone(8, melody[sheet[i]], 150);
    delay(250);
    noTone(8);   
  }
  tone(8, melody[23], 600);
  delay(750);
  noTone(8);
}

void loop() {
  // put your main code here, to run repeatedly:

}
