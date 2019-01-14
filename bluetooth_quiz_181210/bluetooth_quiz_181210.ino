#include <SoftwareSerial.h>
#include <dht11.h>

int DHT11PIN = A0;
dht11 DHT11;

SoftwareSerial bluetooth(2, 3); // 8번 TX, 9번 RX

void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(4, INPUT); // LED OUTPUT
  pinMode(A0, OUTPUT); // LED OUTPUT
}

void loop()
{
  int chk = DHT11.read(DHT11PIN);
  char val = bluetooth.read();

  if (bluetooth.available())
  {
    Serial.write(bluetooth.read());
  }

  if(val == 't')
  {
    Serial.write(bluetooth.read());
  }

  if(val == 'b')
  {
    digitalWrite(8, HIGH);
    Serial.write(bluetooth.read());
  }

  else if(val == 'c')
  {
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    Serial.write(bluetooth.read());
  }
  
}
