#ifndef ZifSocket_h
#define ZifSocket_h
#include "Arduino.h"

class ZifSocket
{
   private:
    int _zif[21];
    const int _socket14[15]={0,1,2,3,4,5,6,7,14,16,17,18,19,20};
    int _analog[4]={A12,A13,A14,A15};
    int _socket16[17]={0,1,2,3,4,5,6,7,8,13,14,16,17,18,19,20};
    int _socket18[19]={0,1,2,3,4,5,6,7,8,9,12,13,14,16,17,18,19,20};
    int _socket20[21]={0,1,2,3,4,5,6,7,8,9,10,11,12,14,16,17,18,19,20};
    void powerOn(int pin);
    void powerOff(int pin);
    void setSensor(int pin);
    void resetSensor(int pin);
    
  public:
    ZifSocket();
    void init(uint8_t p1,uint8_t p2,uint8_t p3,uint8_t p4,uint8_t p5,uint8_t p6,uint8_t p7,uint8_t p8,uint8_t p9,uint8_t p10,uint8_t p11,uint8_t p12,uint8_t p13,uint8_t p14,uint8_t p15,uint8_t p16,uint8_t p17,uint8_t p18,uint8_t p19,uint8_t p20);
    int getPinNumber(uint8_t);
    void setPinNumber(uint8_t,uint8_t);
    int pinDetect();

 
    
};
#endif
