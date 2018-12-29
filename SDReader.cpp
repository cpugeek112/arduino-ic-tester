#include "Arduino.h"
#include "SDReader.h"


SDReader::SDReader()
{
  int initalized = true;  
}

void SDReader::SD_init(){
  pinMode(CHIPSELECT,OUTPUT);
  if (!SD.begin()){
     Serial.println("ERROR:");
     return;
  }
  Serial.println("SD card initalized");
}

void SDReader::testPrint(){
  Serial.println("Worked");
}
