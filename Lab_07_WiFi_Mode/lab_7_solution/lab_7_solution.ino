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

	/* AP MODE */
 
  Serial.print("Configuring access point...");
	WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  Serial.println("Configuration success...");

  /* STA MODE */

  /*******
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  ********/
	
}

void loop() {
  Serial.println(".");
  delay(5000);  /* comment */
}
