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
  InitFirebase();
}

void loop() {
    if (Firebase.ready()) {
      if (Firebase.getString(fbdo, "/Security_System_firebase/opentimehour")) {
        //Success
        Serial.print("Get int data success, String = ");
        Serial.println(fbdo.stringData());
      } else {
        //Failed?, get the error reason from fbdo
  
        Serial.print("Error in getData, ");
        Serial.println(fbdo.errorReason());
      }

      if (Firebase.getString(fbdo, "/Security_System_firebase/opentimeminute")) {
        //Success
        Serial.print("Get int data success, String = ");
        Serial.println(fbdo.stringData());
      } else {
        //Failed?, get the error reason from fbdo
  
        Serial.print("Error in getData, ");
        Serial.println(fbdo.errorReason());
      }
    }
  
    if(digitalRead(Switch) == 1){    
           Camera_capture();
           Serial.println("OK"); 
    }
    
    printLocalTime();
    delay(1000);
}
