int a_pin = 5;    // segment의 a led
int b_pin = 9;    // segment의 b led
int c_pin = A2;   // segment의 c led
int d_pin = A4;   // segment의 d led
int e_pin = A5;   // segment의 e led
int f_pin = 6;    // segment의 f led
int g_pin = A1;   // segment의 g led
int dp_pin = A3;    // segment의 dp led

int dig1 = 4;   // 좌측 기준으로 첫번째 segment
int dig2 = 7;   // 좌측 기준으로 두번째 segment
int dig3 = 8;   // 좌측 기준으로 세번째 segment
int dig4 = A0;   // 좌측 기준으로 번째 segment

int btn1_pin = 13;
int btn2_pin = 12;
int btn3_pin = 3;
int btn4_pin = 2;

int sound_pin = 10;

int start = 0;

byte digits[10][7] = {
  {1,1,1,1,1,1,0},  // 0
  {0,1,1,0,0,0,0},  // 1
  {1,1,0,1,1,0,1},  // 2
  {1,1,1,1,0,0,1},  // 3
  {0,1,1,0,0,1,1},  // 4
  {1,0,1,1,0,1,1},  // 5
  {1,0,1,1,1,1,1},  // 6
  {1,1,1,0,0,0,0},  // 7
  {1,1,1,1,1,1,1},  // 8
  {1,1,1,1,0,1,1}   // 9
};

int digitPos[4] = {dig1, dig2, dig3, dig4};

int minuite = 0;
int seconds = 0;

int min10 = 0;
int min1 = 0;
int sec10 = 0;
int sec1 = 0;
volatile int bPlus = 0;
int number = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  
  pinMode(a_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(c_pin, OUTPUT);
  pinMode(d_pin, OUTPUT);
  pinMode(e_pin, OUTPUT);
  pinMode(f_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  
  pinMode(dp_pin, OUTPUT);

  pinMode(btn1_pin, INPUT);
  pinMode(btn2_pin, INPUT);
  pinMode(btn3_pin, INPUT);
  pinMode(btn4_pin, INPUT);

  attachInterrupt(0, btn3ISR, RISING);
  attachInterrupt(1, btn4ISR, RISING);

   clearAll();
    selectDigitPos(1);
    printNumber(min10);
    delayMicroseconds(100000);  
    selectDigitPos(2);
    printNumber(min1);
    delayMicroseconds(100000);  
    selectDigitPos(3);
    printNumber(sec10);
    delayMicroseconds(100000);  
    selectDigitPos(4);
    printNumber(sec1);
    delayMicroseconds(100000);  
  
  
}

void loop() {
  if(digitalRead(btn1_pin) == HIGH){
    ++min1;
    if(min1 > 10){
      min1 = 0;
      ++min10;
      if(min10 > 6){
        min10 = 0;        
      }
    }
    delay(200);
    clearAll();
    selectDigitPos(1);
    printNumber(min10);
    delayMicroseconds(100000);
    selectDigitPos(2);
    printNumber(min1);
    delayMicroseconds(100000);
  }
  if(digitalRead(btn2_pin) == HIGH){
    --sec1;
    if(sec1 < 0){
      sec1 = 9;
      --sec10;
      if(sec10 < 0){
        sec10 = 5;        
      }
    }
    delay(200);
    clearAll();
    selectDigitPos(3);
    printNumber(sec10);
    delayMicroseconds(100000);
    selectDigitPos(4);
    printNumber(sec1);
    delayMicroseconds(100000);
  }

  if(start == 1){
    if(sec1==0 && sec10 == 0 && min1 == 0 && min10 == 0){
      tone(10, 1000, 200);
      delay(200);
      noTone(10);
      delay(200);
      start = 0;
      return;
    }else{
      --sec1;
    if(sec1 < 0){
      --sec10;
      sec1 = 9;
      if(sec10 < 0){
        --min1;
        sec10 = 5;
        if(min1 < 0){
          --min10;
          min1 = 9;
          if(min10 < 0){
            min10 = 0;
          }
        }
      }
    }
    delay(1000);
    clearAll();
    selectDigitPos(1);
    printNumber(min10);
    delayMicroseconds(1000000);  
    selectDigitPos(2);
    printNumber(min1);
    delayMicroseconds(1000000);  
    selectDigitPos(3);
    printNumber(sec10);
    delayMicroseconds(1000000);  
    selectDigitPos(4);
    printNumber(sec1);
    delayMicroseconds(1000000);  
    }
  }
}

void selectDigitPos(int pos) {
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);

  digitalWrite(digitPos[pos-1], LOW);
}

void printNumber(int number) {
  digitalWrite(a_pin, digits[number][0]);
  digitalWrite(b_pin, digits[number][1]);
  digitalWrite(c_pin, digits[number][2]);
  digitalWrite(d_pin, digits[number][3]);
  digitalWrite(e_pin, digits[number][4]);
  digitalWrite(f_pin, digits[number][5]);
  digitalWrite(g_pin, digits[number][6]);
}

void clearAll() {
  digitalWrite(a_pin, LOW);
  digitalWrite(b_pin, LOW);
  digitalWrite(c_pin, LOW);
  digitalWrite(d_pin, LOW);
  digitalWrite(e_pin, LOW);
  digitalWrite(f_pin, LOW);
  digitalWrite(g_pin, LOW);
  
  digitalWrite(dp_pin, LOW);
}

void printDP() {
  digitalWrite(dp_pin, HIGH);
}

void btn3ISR() {  
  start = 1;
}

void btn4ISR() {
  start = 0;
}
