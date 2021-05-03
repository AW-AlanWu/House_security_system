# House_security_system

>> 整個系統以arduino、app inventor為主，其中Thingspeak作為IOT溝通

## Arduino Part

### Method

1. void setup()
	* initialize serial
	* initialize time
	* initialize UDP
	* initialize ThingSpeak
	* initialize Anything!XD
2. void loop()
	* 比較當前系統時間與ThingSpeak上時鐘的時間是否相同，如果相同則進入迴圈(之後可能加入拍照功能)
	* show the data from ThingSpeak
	* and... just a loop XD
3. void sendNTPpacket(char *ntpSrv)
	* send the UDP packet to the NTP sever
4. void InitWiFi()
	* initialize ESP
5.  unsigned long getUnixTime()
	* send and recieve the UDP packet 
	* 增加如果packet接收失敗的話則以迴圈重複發送packet的功能
6. String getTime(unsigned long epoch)
	* 回傳格式如"16:9"的字串(為了配合APP inventor而改變了時間格式)
7. void sync_clock()
	* sync the clock
	* turn UTC time to taiwan time
8. bool checkStatusCode(int statusCode)
	* check statuscode
9. String readThingSpeakData(unsigned long ChannelNumber, unsigned int FieldNumber, const char* ReadAPIKey)
	* 處理所有有關"讀取"ThingSpeak資料庫的工作，簡而言之--就是讀取Channel
	* 關於參數部分有點尷尬，由於想要將"讀取"的工作完全獨立出來，所以不打算直接使用全域變數，之後可能會再修正
	
### Library

1. [TimeLib](https://github.com/PaulStoffregen/Time "Title")
2. [TimeAlarms](https://github.com/PaulStoffregen/TimeAlarms "Title")
3. [WiFiEsp](https://github.com/bportaluri/WiFiEsp "Title")
4. [Thingspeak](https://github.com/mathworks/thingspeak-arduino "Title")

## APP Inventor Part

### Appreance

#### Screen1:

![alt text](https://github.com/AW-AlanWu/House_security_system/blob/master/AppInventor/Screen1_apprence.PNG)

#### Screen2:

![alt text](https://github.com/AW-AlanWu/House_security_system/blob/master/AppInventor/Screen2_apprence.PNG)

### Code

#### Screen1:

![alt text](https://github.com/AW-AlanWu/House_security_system/blob/master/AppInventor/screen1_code.PNG)


#### Screen2:

![alt text](https://github.com/AW-AlanWu/House_security_system/blob/master/AppInventor/screen2_code.PNG)

## Building Part

### Perspective View(Entity):

![alt text](https://github.com/AW-AlanWu/House_security_system/blob/master/Building/Perspective%201.png)

### Perspective View(Perspective):

![alt text](https://github.com/AW-AlanWu/House_security_system/blob/master/Building/Perspective%202.png)

### Top View

![alt text](https://github.com/AW-AlanWu/House_security_system/blob/master/Building/Top.PNG)

## ESP32-CAM part

>> 當前功能：拍照、取得目前時間、將訊息及照片發送至LINE Notify

### Method

1. void setup()
	* initialize serial
	* initialize camera
	* initialize WiFi
	* initialize Time
	* initialize Anything!XD
2. void loop()
	* If switch is on, then take a picture and send it to line notify
	* print the time
3. initCamera()
	* I don't now how it work
	* As the name suggests
4. Send_line(uint8_t *image_data,size_t   image_size)
	* As the name suggests
5. Camera_capture()
	* I don't now how it work
	* As the name suggests
6. InitWiFi()
	* As the name suggests
7. printLocalTime()
	* As the name suggests
	
### Library

1. [TridentTD_LineNotify](https://github.com/TridentTD/TridentTD_LineNotify "Title")

* 參考資料

>> [UdpNTPClient Example](https://github.com/bportaluri/WiFiEsp/blob/master/examples/UdpNTPClient/UdpNTPClient.ino "Title")

>> [利用 NTP 伺服器來同步 Arduino 系統時鐘](https://yhhuang1966.blogspot.com/2016/08/ntp-arduino.html?fbclid=IwAR2rHr-UXKwTk_lbIR3KPbFoBjla3ZaixcyNbTWjQ5ldJEWcKkSAZlSY7DI "Title")

>> [02 與LINE的連動](https://sites.google.com/site/wenyuwebbit/22-esp32-cam/02-yuline-de-lian-dong "Title")

>> [01 認識ESP32-CAM](https://sites.google.com/site/wenyuwebbit/22-esp32-cam/01-ren-shiesp32-cam "Title")

>> [USB TTL driver(choose the old version)](http://www.prolific.com.tw/US/ShowProduct.aspx?p_id=225&pcid=41 "Title")

>> [ESP32-Cam 讀取網際網路上的時間](http://pizgchen.blogspot.com/2020/08/esp32-esp32-cam_13.html "Title")
