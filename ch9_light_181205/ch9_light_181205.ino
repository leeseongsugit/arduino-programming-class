void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int light = analogRead(A0);
  int ledLight = map(light, 0, 100, 255, 0);
  analogWrite(9, ledLight);
}
