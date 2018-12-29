#include "Arduino.h"
#include "ZifSocket.h"


ZifSocket::ZifSocket(uint8_t p1,uint8_t p2,uint8_t p3,uint8_t p4,uint8_t p5,uint8_t p6,uint8_t p7,uint8_t p8,uint8_t p9,uint8_t p10,uint8_t p11,uint8_t p12,uint8_t p13,uint8_t p14,uint8_t p15,uint8_t p16,uint8_t p17,uint8_t p18,uint8_t p19,uint8_t p20)
{
  setPinNumber(1,p1);   setPinNumber(2,p2);     setPinNumber(3,p3);     setPinNumber(4,p4);
  setPinNumber(5,p5);   setPinNumber(6,p6);     setPinNumber(7,p7);     setPinNumber(8,p8);
  setPinNumber(9,p9);   setPinNumber(10,p10);   setPinNumber(11,p11);   setPinNumber(12,p12);
  setPinNumber(13,p13); setPinNumber(14,p14);   setPinNumber(15,p15);   setPinNumber(16,p16);
  setPinNumber(17,p17); setPinNumber(18,p18);   setPinNumber(19,p19);   setPinNumber(20,p20);
}

void ZifSocket::powerOn(int pin){
  pinMode(pin,OUTPUT);
  digitalWrite(pin,HIGH);
}

void ZifSocket::powerOff(int pin){
  pinMode(pin,INPUT_PULLUP);
  digitalWrite(pin,HIGH);
}

void ZifSocket::setSensor(int pin){
  pinMode(pin,INPUT_PULLUP);
  digitalWrite(pin,LOW);
}

void ZifSocket::resetSensor(int pin){
  pinMode(pin,INPUT_PULLUP);
  digitalWrite(pin,HIGH);
}

int ZifSocket::getPinNumber(uint8_t pin){
  return this->_zif[pin];
}

void ZifSocket::setPinNumber(uint8_t zpin,uint8_t apin ){
  _zif[zpin]=apin;
}


int ZifSocket::pinDetect(){
  int vcc_pin = _zif[20];
  int gnd_pins[] = {_zif[7],_zif[8],_zif[9],_zif[10]};
  int numberPins = 0;
  powerOn(vcc_pin);

  for(int gnd:gnd_pins){
    setSensor(gnd);
  }
  delay(10);
  

  for(int l=0;l<20;l++){
    if(analogRead(gnd_pins[3])>0){
      numberPins=20;
      break;
    }
     else if(analogRead(gnd_pins[2])>0 and numberPins<20){
      numberPins=18;
      break;
    }
    else if(analogRead(gnd_pins[1])>0 and numberPins<18){
      numberPins=16;
      break;
    }
    else if(analogRead(gnd_pins[0])>0 and numberPins<16){
      numberPins=14;
      continue;
    }
    
  }
  return numberPins;
}
