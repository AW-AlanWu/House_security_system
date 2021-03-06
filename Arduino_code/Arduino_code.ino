#include <ThingSpeak.h>
#include <TimeAlarms.h>
#include <TimeLib.h>
#include "WiFiEsp.h"
#include "WiFiEspUdp.h"

char ssid[] = "";            // your network SSID (name)
char pass[] = "";        // your network password

char timeServer[] = "time.nist.gov";  // NTP server
unsigned int localPort = 2390;        // local port to listen for UDP packets

const int NTP_PACKET_SIZE = 48;  // NTP timestamp is in the first 48 bytes of the message
const int UDP_TIMEOUT = 2000;    // timeout in miliseconds to wait for an UDP packet to arrive

byte packetBuffer[NTP_PACKET_SIZE]; // buffer to hold incoming and outgoing packets

// A UDP instance to let us send and receive packets over UDP
WiFiEspUDP Udp;

WiFiEspClient client;

unsigned long ChannelNumber = 0;
unsigned int startTimeFieldNumber = 1;
unsigned int stopTimeFieldNumber = 2;
const char * myReadAPIKey = "";

void setup()
{
  // initialize serial for debugging
  Serial.begin(9600);
  // initialize serial for ESP module
  Serial1.begin(9600);
  
  InitWiFi();
  Udp.begin(localPort);

  sync_clock();
  Alarm.timerRepeat(60, sync_clock);

  ThingSpeak.begin(client);
}

void loop()
{
  String startTime = readThingSpeakData(ChannelNumber, startTimeFieldNumber, myReadAPIKey);
  String stopTime = readThingSpeakData(ChannelNumber, stopTimeFieldNumber, myReadAPIKey);

  if(getTime() == startTime) {
    while(getTime() != stopTime) {
      
    }
  }
}

// send an NTP request to the time server at the given address
void sendNTPpacket(char *ntpSrv)
{
  // set all bytes in the buffer to 0
  memset(packetBuffer, 0, NTP_PACKET_SIZE);
  // Initialize values needed to form NTP request
  // (see URL above for details on the packets)

  packetBuffer[0] = 0b11100011;   // LI, Version, Mode
  packetBuffer[1] = 0;     // Stratum, or type of clock
  packetBuffer[2] = 6;     // Polling Interval
  packetBuffer[3] = 0xEC;  // Peer Clock Precision
  // 8 bytes of zero for Root Delay & Root Dispersion
  packetBuffer[12]  = 49;
  packetBuffer[13]  = 0x4E;
  packetBuffer[14]  = 49;
  packetBuffer[15]  = 52;

  // all NTP fields have been given values, now
  // you can send a packet requesting a timestamp:
  Udp.beginPacket(ntpSrv, 123); //NTP requests are to port 123

  Udp.write(packetBuffer, NTP_PACKET_SIZE);

  Udp.endPacket();
}

void InitWiFi() {
  int status = WL_IDLE_STATUS;     // the Wifi radio's status
  // initialize ESP module
  WiFi.init(&Serial1);
  // check for the presence of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");

    while (true);
  }

  Serial.println("Connecting to AP ...");

  // attempt to connect to WiFi network
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(500);
  }

  // you're connected now, so print out the data
  Serial.println("Connected to AP");
  IPAddress ip = WiFi.localIP();
  Serial.print("IP: ");
  Serial.println(ip);
}

unsigned long getUnixTime() {
  do {  //if packet failed, then send packet again
    sendNTPpacket(timeServer); // send an NTP packet to a time server
    
    // wait for a reply for UDP_TIMEOUT miliseconds
    unsigned long startMs = millis();
    while (!Udp.available() && (millis() - startMs) < UDP_TIMEOUT) {}
  } while(Udp.parsePacket() != 48);
  
  Serial.println(Udp.parsePacket());
  
  if (Udp.parsePacket()) {
    Serial.println("packet received");
    // We've received a packet, read the data from it into the buffer
    Udp.read(packetBuffer, NTP_PACKET_SIZE);

    // the timestamp starts at byte 40 of the received packet and is four bytes,
    // or two words, long. First, esxtract the two words:

    unsigned long highWord = word(packetBuffer[40], packetBuffer[41]);
    unsigned long lowWord = word(packetBuffer[42], packetBuffer[43]);
    // combine the four bytes (two words) into a long integer
    // this is NTP time (seconds since Jan 1 1900):
    unsigned long secsSince1900 = highWord << 16 | lowWord;

    // now convert NTP time into everyday time:
    // Unix time starts on Jan 1 1970. In seconds, that's 2208988800:
    const unsigned long seventyYears = 2208988800UL;
    // subtract seventy years and time different:
    unsigned long epoch = secsSince1900 - seventyYears;
    // return Unix time:
    return epoch;
  }
}

String getTime() {  //return Date and Time
  String Time;
  
  byte h = hour();
  
  Time.concat(h);
  Time.concat(':');
  
  byte m = minute();
  Time.concat(m);

  return Time;  //傳回格式如 16:09:23 的日期時間字串
}

void sync_clock() {
  //Taiwan time different in seconds, that's 28800:
  setTime(getUnixTime() + 28800L);
}

bool checkStatusCode(int statusCode) {
  if(statusCode == 200) {
    return true;
  } else {
    Serial.println("Problem reading channel. HTTP error code " +
                   String(statusCode));
    return false;
  }
}

String readThingSpeakData(unsigned long ChannelNumber, unsigned int FieldNumber, const char* ReadAPIKey) {
  int statusCode = 0;
  do {
    String data = ThingSpeak.readStringField(ChannelNumber, FieldNumber, ReadAPIKey);
    statusCode = ThingSpeak.getLastReadStatus();
  
    if (checkStatusCode(statusCode))
      return data;
  } while(!(checkStatusCode(statusCode)));
}
