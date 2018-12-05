int red = 13;
int yel = 12;
int gre = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(yel, OUTPUT);
  pinMode(gre, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(yel, HIGH);
  delay(500);
  digitalWrite(yel, LOW);
  delay(500);
  digitalWrite(gre, HIGH);
  delay(500);
  digitalWrite(gre, LOW);
  delay(500);

}
