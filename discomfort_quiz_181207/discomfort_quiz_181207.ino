#include <dht11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int DHT11PIN = A1;            //Signal 이 연결된 아두이노의 핀번호
 
dht11 DHT11;
float temper;
float humid;
float now;
float temp1, temp2;
void setup()
{
  Serial.begin(9600);  //시리얼 통신속도 설정
  lcd.begin();
  lcd.backlight();
}
  
void loop()
{
  int chk = DHT11.read(DHT11PIN);
  temper = DHT11.temperature;
  humid = DHT11.humidity;
  temp1 = 9/5*temper;
  temp2 = 0.55 * (1 - humid/100)*(temp1-26);
  now = temp1-temp2+32;

  lcd.clear();

  lcd.print(now);
  lcd.print("/ ");
  if(now >= 80){
    lcd.print(" -- very high " );
  }else if(now >= 75){
    lcd.print(" -- high " );
  }else if(now >= 68){
    lcd.print(" -- normal " );
  }else{
    lcd.print(" -- low " );
  }

  delay(2000);
}
