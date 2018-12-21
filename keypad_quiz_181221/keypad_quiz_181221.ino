#include<Keypad.h>
#include<String.h>
#include<Stdlib.h>


const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
int led_pin = 13;
boolean blink = false;
String password = "1234";
String input = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led_pin, OUTPUT);
  keypad.addEventListener(listener);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();
  if(key != NO_KEY) {
     // Serial.println(key);
     Serial.println(input);
    } 
}

void listener(KeypadEvent key){
  switch(keypad.getState()){
    case PRESSED:
      
      if(key== 'A'){
        if(input == password){
          digitalWrite(led_pin, true);  
          Serial.println("Correct");
        }else{
          digitalWrite(led_pin, false);
        }
        input= "";
      }else{
        input += key;
      }
      break;
  }
}
