#include <Wire.h>
#include "Keyboard.h"

const int addr = 0x8; 

int bootStatusLED = 4;
int dakutenModeStatusLED = 5;
int hanDakutenModeStatusLED = 6;
int suujiModeStatusLED = 7;
int alphabetModeStatusLED = 8;
int youonnModeStatusLED = 9;

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  Wire.begin(addr); 
  Wire.onReceive(onReceiveWire); 

  pinMode(bootStatusLED, OUTPUT);
  pinMode(dakutenModeStatusLED, OUTPUT);
  pinMode(hanDakutenModeStatusLED, OUTPUT);
  pinMode(suujiModeStatusLED, OUTPUT);
  pinMode(alphabetModeStatusLED, OUTPUT);
  pinMode(youonnModeStatusLED, OUTPUT);
}

void onReceiveWire(int bitstream) {
  //int ci = Wire.read();
  char c = Wire.read();
  // 動かん...。
  switch (c) {
    case 0x00:  
      Serial.write("0x0");
      //
      digitalWrite(bootStatusLED, HIGH);
      //
      digitalWrite(dakutenModeStatusLED, LOW);
      digitalWrite(hanDakutenModeStatusLED, LOW);
      digitalWrite(suujiModeStatusLED, LOW);
      digitalWrite(alphabetModeStatusLED, LOW);
      digitalWrite(youonnModeStatusLED, LOW);
      //
      break;
    case 0x01:
      Serial.write("0x01");
      //
      digitalWrite(dakutenModeStatusLED, HIGH);
      //
      //digitalWrite(dakutenModeStatusLED, LOW);
      digitalWrite(hanDakutenModeStatusLED, LOW);
      digitalWrite(suujiModeStatusLED, LOW);
      digitalWrite(alphabetModeStatusLED, LOW);
      digitalWrite(youonnModeStatusLED, LOW);
      //
      break;
    case 0x02:
      Serial.write("0x02");
      //
      digitalWrite(hanDakutenModeStatusLED, HIGH);
      //
      digitalWrite(dakutenModeStatusLED, LOW);
      //digitalWrite(hanDakutenModeStatusLED, LOW);
      digitalWrite(suujiModeStatusLED, LOW);
      digitalWrite(alphabetModeStatusLED, LOW);
      digitalWrite(youonnModeStatusLED, LOW);
      //
      break;
    case 0x03:
      Serial.write("0x03");
      //
      digitalWrite(suujiModeStatusLED, HIGH);
      //
      digitalWrite(dakutenModeStatusLED, LOW);
      digitalWrite(hanDakutenModeStatusLED, LOW);
      //digitalWrite(suujiModeStatusLED, LOW);
      digitalWrite(alphabetModeStatusLED, LOW);
      digitalWrite(youonnModeStatusLED, LOW);
      //
      break;
    case 0x04:
      Serial.write("0x04");
      //
      digitalWrite(alphabetModeStatusLED, HIGH);
      //
      digitalWrite(dakutenModeStatusLED, LOW);
      digitalWrite(hanDakutenModeStatusLED, LOW);
      digitalWrite(suujiModeStatusLED, LOW);
      //digitalWrite(alphabetModeStatusLED, LOW);
      digitalWrite(youonnModeStatusLED, LOW);
      //
      break;
    case 0x05:
      Serial.write("0x05");
      //
      digitalWrite(youonnModeStatusLED, HIGH);
      //
      digitalWrite(dakutenModeStatusLED, LOW);
      digitalWrite(hanDakutenModeStatusLED, LOW);
      digitalWrite(suujiModeStatusLED, LOW);
      digitalWrite(alphabetModeStatusLED, LOW);
      //digitalWrite(youonnModeStatusLED, LOW);
      //
      break;
    case 0x06:
      Serial.write("0x06");
      //
      //digitalWrite(bootStatusLED, LOW);
      digitalWrite(dakutenModeStatusLED, LOW);
      digitalWrite(hanDakutenModeStatusLED, LOW);
      digitalWrite(suujiModeStatusLED, LOW);
      digitalWrite(alphabetModeStatusLED, LOW);
      digitalWrite(youonnModeStatusLED, LOW);
      //
      break;
    default:
      Serial.write(c);
      int ci = c - 0;
      Keyboard.write(ci); 
      break;
  }
}

void loop() {
  /*
  digitalWrite(bootStatusLED, HIGH);
  digitalWrite(dakutenModeStatusLED, HIGH);
  digitalWrite(hanDakutenModeStatusLED, HIGH);
  digitalWrite(suujiModeStatusLED, HIGH);
  digitalWrite(alphabetModeStatusLED, HIGH);
  digitalWrite(youonnModeStatusLED, HIGH);
  delay(1000);
  digitalWrite(bootStatusLED, LOW);
  digitalWrite(dakutenModeStatusLED, LOW);
  digitalWrite(hanDakutenModeStatusLED, LOW);
  digitalWrite(suujiModeStatusLED, LOW);
  digitalWrite(alphabetModeStatusLED, LOW);
  digitalWrite(youonnModeStatusLED, LOW);
  delay(1000);
  */
}
