#House_security_system

>>��Өt�ΥHarduino�Bapp inventer���D�A�䤤Thingspeak�@�����q

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
	
[�ѦҸ��](https://github.com/bportaluri/WiFiEsp/blob/master/examples/UdpNTPClient/UdpNTPClient.ino "Title")
