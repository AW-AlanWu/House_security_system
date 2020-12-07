# House_security_system

>> 整個系統以arduino、app inventor為主，其中Thingspeak作為IOT溝通

## Arduino Part

### Method

1. void setup()
	* initialize serial
2. void loop()
	* just a loop XD
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
	
### Library

1. [TimeLib](https://github.com/PaulStoffregen/Time "Title")
2. [TimeAlarms](https://github.com/PaulStoffregen/TimeAlarms "Title")
3. [WiFiEsp](https://github.com/bportaluri/WiFiEsp "Title")

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

* 參考資料
>> [UdpNTPClient Example](https://github.com/bportaluri/WiFiEsp/blob/master/examples/UdpNTPClient/UdpNTPClient.ino "Title")
>> [利用 NTP 伺服器來同步 Arduino 系統時鐘](https://yhhuang1966.blogspot.com/2016/08/ntp-arduino.html?fbclid=IwAR2rHr-UXKwTk_lbIR3KPbFoBjla3ZaixcyNbTWjQ5ldJEWcKkSAZlSY7DI "Title")
