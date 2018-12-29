// Serial IC tester
#include "ZifSocket.h"
#include "SD.h"

ZifSocket socket(22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41);



void setup() {
  Serial.begin(115200);
  Serial.println(String(socket.pinDetect()));
s

}

void loop() {
  // put your main code here, to run repeatedly:

}
