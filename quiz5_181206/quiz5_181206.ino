int a_pin = 3;    // segment의 a led
int b_pin = 7;    // segment의 b led
int c_pin = A2;   // segment의 c led
int d_pin = A4;   // segment의 d led
int e_pin = A5;   // segment의 e led
int f_pin = 4;    // segment의 f led
int g_pin = A1;   // segment의 g led
int dp_pin = A3;    // segment의 dp led

int dig1 = 2;   // 좌측 기준으로 첫번째 segment
int dig2 = 5;   // 좌측 기준으로 두번째 segment
int dig3 = 6;   // 좌측 기준으로 세번째 segment
int dig4 = A0;   // 좌측 기준으로 번째 segment

int btn1_pin = 10;
int btn2_pin = 11;
int btn3_pin = 12;
int btn4_pin = 13;


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

int val = 0;
int val2 = 0;
int val1 = 0;

int target = 0;

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
}

void loop() {
  if(btn1_pin == HIGH){
    ++target;
    if(target > 60){
      target = 0;
    }
  }
  if(btn2_pin == HIGH){
    --target;
    if(target < 0){
      target = 60;
    }
  }

  if(btn3_pin == HIGH){
        
  }
  val = target - millis() / 1000;

  val2 = (val / 10) % 10;
  val1 = val % 10;

  if (val >= 10)
  {
    clearAll();
    selectDigitPos(3);
    printNumber(val2);
    delayMicroseconds(1000);
  }

  if (val >= 0)
  {
    clearAll();
    selectDigitPos(4);
    printNumber(val1);
    delayMicroseconds(1000);
  }
  
  if(val == 0 ){
    tone(8, 100, 200);
    delay(1000);
    noTone(8); 
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
