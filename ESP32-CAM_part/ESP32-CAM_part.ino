#include "secrets.h"

void setup() {
  Serial.begin(115200);
  while (!Serial) {  ;  }
  pinMode(Led_Flash, OUTPUT);
  pinMode(Led_run, OUTPUT);

  InitWiFi();

  LINE.setToken(LINE_TOKEN);

   Udp.begin(localPort);

   sync_clock();
   Alarm.timerRepeat(60, sync_clock);

   initCamera();
}

void loop() {
    if(digitalRead(Switch) == 1){    
           Camera_capture();
           Serial.println("OK"); 
    }

    Serial.println(getTime());
    //Serial.println(digitalRead(Switch));
    delay(200);
}
