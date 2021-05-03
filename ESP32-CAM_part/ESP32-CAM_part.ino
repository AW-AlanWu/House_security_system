#include "secrets.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) {  ;  }
  pinMode(Led_Flash, OUTPUT);
  pinMode(Led_run, OUTPUT);

  InitWiFi();
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
  LINE.setToken(LINE_TOKEN);

  initCamera();
}

void loop() {
    if(digitalRead(Switch) == 1){    
           Camera_capture();
           Serial.println("OK"); 
    }
    printLocalTime();
    delay(1000);
}
