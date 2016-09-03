/************************
@Since 2016/09/03
@Author AppStack.cc
@Tools Arduino 1.6.11, ESP8266 2.3.0
@Desc Hello World
@Note Lab 01
***********************/
#include <stdint.h>

void setup() {
  
  // initialize serial port,  baudrate 9600 bps
  Serial.begin(9600);
  
}

void loop() {

  //use Serial.print ro Serial.println
  Serial.print("Hello, ");
  Serial.println("World.");

  Serial.println("I am ESP8266 :)");
  Serial.println("");
  

}




