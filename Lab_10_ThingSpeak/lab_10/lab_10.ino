#include <ESP8266WiFi.h>

#include "DHT.h"

#define DHTPIN D1 
#define DHTTYPE DHT11     //DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

 

DHT dht(DHTPIN, DHTTYPE);
const char* ssid     = "";    // SSID Wifi
const char* password = "";   // Password Wifi
const char* host = "api.thingspeak.com";    // Host ของ thingspeak ไม่ต้องแก้ไข
const char* api   = "";  //API Key ที่เราจำไว้ ในขั้นต้นเมื่อกี้

void setup() {
  Serial.begin(115200);
  delay(10);
  // We start by connecting to a WiFi network
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
  Serial.println("DHTxx test!");
  dht.begin();

}

 




void loop() {

  delay(5000);


  // Read DHT11
  

  // Send data to thingspeak

}
