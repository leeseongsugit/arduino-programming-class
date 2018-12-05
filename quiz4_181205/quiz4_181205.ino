// preprocessor
#define C 262   // 도
#define D 294   // 레
#define E 330   // 미
#define F 349   // 파
#define G 392   // 솔
#define A 440   // 라
#define B 494   // 시
#define H 523   // 높은 도

int piezo_pin = 8;
int song1_pin = 12;
int song2_pin = 13;
int tempo = 250;
int notes[24] = {G,G,A,A,G,G,E,G,G,E,E,D,G,G,A,A,G,G,E,G,E,D,E,C};
void setup() {
  pinMode(piezo_pin, OUTPUT);
  pinMode(song1_pin, INPUT);
  pinMode(song2_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(song1_pin) == HIGH) {
    for(int i = 0; i < 12; i++) {
      Serial.println("play1");
      tone(piezo_pin, notes[i], tempo);
      delay(250);
    }
  }

  if(digitalRead(song2_pin) == HIGH) {
    for(int i = 12; i <= 24; i++) {
      Serial.println("play2");
      tone(piezo_pin, notes[i], tempo);
      delay(250);
    }
  }
  Serial.println("no play");
      
}
