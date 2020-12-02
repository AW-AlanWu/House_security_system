#House_security_system

>>整個系統以arduino、app inventer為主，其中Thingspeak作為溝通

##Arduino Part
###Method

1. setup()
	* initialize serial
2. loop()
	* just a loop XD
3. sendNTPpacket(char *ntpSrv)
	* send the UDP packet to the NTP sever
4. InitWiFi()
	* initialize ESP
5. getUnixTime()
	* send and recieve the UDP packet
	* turn UTC time to taiwan time
6. printDateTime(unsigned long epoch)
	* print the Taiwan time
	
[參考資料](https://github.com/bportaluri/WiFiEsp/blob/master/examples/UdpNTPClient/UdpNTPClient.ino "Title")
