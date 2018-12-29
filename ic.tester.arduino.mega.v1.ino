// Serial IC tester
#include "ZifSocket.h"
#include "SDReader.h"



ZifSocket socket;
SDReader data;

void setup() {
  Serial.begin(115200);
  socket.init(22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41);
  data.SD_init();
  while(!Serial){;}
  Serial.println(String(socket.pinDetect()));

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(socket.pinDetect());
  delay(5000);
  
}
