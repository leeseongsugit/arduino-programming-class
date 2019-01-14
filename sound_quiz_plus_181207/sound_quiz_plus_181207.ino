#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sound_pin = A0;
int led1_pin = 11;
int led2_pin = 10;
int led3_pin = 9;
int init_btn = 8;
int count = 0;
int count2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
  pinMode(led3_pin, OUTPUT);
  pinMode(init_btn, INPUT);

  lcd.begin();
  lcd.backlight();
  lcd.print("(^^)");
}

void loop() {
  // put your main code here, to run repeatedly:
  int sound_value = analogRead(sound_pin);
  
  if(sound_value >= 1023){
    ++count;
  }
  if(count >= 5 && count2 < 12){
    lcd.scrollDisplayRight();
    delay(200);
    count = 0;
    ++count2;
  }

  if(count2 == 12){
    lcd.clear();
    lcd.print("   Game Over   ");
    delay(1000);
  }
  if(digitalRead(init_btn) == HIGH){
    count = 0;
  }
}
