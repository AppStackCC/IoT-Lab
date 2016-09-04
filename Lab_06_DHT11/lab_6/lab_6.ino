#include <ESP8266WiFi.h>


// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define _DHTPIN_ D3     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define _DHTTYPE_ DHT11   // DHT 11

//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT DHT_11(_DHTPIN_, _DHTTYPE_);

#define _TIME_DHT_  2000
#define _TIME_BLINK_  500

#define _LED_STATUS_ D1
#define _LED_ALARM_ D0


void setup() {
  Serial.begin(115200);
  Serial.println("DHT11 test!");

  pinMode(_LED_STATUS_,OUTPUT);
  pinMode(_LED_ALARM_,OUTPUT);

  DHT_11.begin();
}

void loop() {

  uint32_t timer = millis();
  static uint32_t timer_dht = timer;
  static uint32_t timer_blink = timer;
  static uint8_t toggle_flag = 0;


  if((timer - timer_blink) >= _TIME_BLINK_)
  {
    timer_blink = timer;
    if(toggle_flag == 1)
    { 
      digitalWrite(_LED_STATUS_,HIGH);
      toggle_flag = 0;
    }
    else
    {
      digitalWrite(_LED_STATUS_,LOW);
      toggle_flag = 1;
    }
  }


  if((timer - timer_dht) >= _TIME_DHT_)
  {
    timer_dht = timer;
    
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = DHT_11.readHumidity();
    // Read temperature as Celsius (the default)
    float t = DHT_11.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    float f = DHT_11.readTemperature(true);
  
    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t) || isnan(f)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }
  
    // Compute heat index in Fahrenheit (the default)
    float hif = DHT_11.computeHeatIndex(f, h);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic = DHT_11.computeHeatIndex(t, h, false);

    if (t >= 27.0f)
    {
      digitalWrite(_LED_ALARM_,HIGH);
    }
    else
    {
      digitalWrite(_LED_ALARM_,LOW);
    }
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print(f);
    Serial.print(" *F\t");
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");
    Serial.print(hif);
    Serial.println(" *F");
   
  }
}
