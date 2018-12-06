int led_pin = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    int light = analogRead(A0);
    int ledLight = map(light, 0, 1000, 255, 0);

    if(light <= 500){
      digitalWrite(led_pin, HIGH);
    }else{
      digitalWrite(led_pin, LOW);
    }
}
