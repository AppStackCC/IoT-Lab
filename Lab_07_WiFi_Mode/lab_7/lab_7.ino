/*
 * Lab 5 : Wifi AP , STA
 * ทดลองการใช้งาน WiFi บนโมดูล ESP8266
 * AP => Access Point
 * STA -> Station
 */


#include <ESP8266WiFi.h>
#include <WiFiClient.h> 

const char *ssid = "ESPXX";
const char *password = "123456";

void setup() {
	delay(1000);
	Serial.begin(115200);
	Serial.println();


  // AP
  // WiFi.softAP(ssid, password);
  // IPAddress myIP = WiFi.softAPIP();


  // STA
  // WiFi.begin(ssid, password);
  // WiFi.status()
  // WiFi.localIP()

  
	/* AP MODE */
  // ....

  /* STA MODE */
  // ....
	
}

void loop() {
  Serial.println(".");
  delay(500);  /* comment */
}
