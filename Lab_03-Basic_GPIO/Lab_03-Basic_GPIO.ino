/************************
@Since 2016/09/04
@Author AppStack.cc
@Tools Arduino 1.6.11, ESP8266 2.3.0
@Desc Basic GPIO
@Note Lab 03
***********************/
void setup() {
  
  // initialize pin D0, D1 as output
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  
  // initialize pin D2 as Input (Try Mode INPUT, INPUT_PULLUP)
  pinMode(D2,INPUT_PULLUP);
  
}

void loop() {

    //Read GPIO pin D2 and Write to GPIO D1
    
    if(digitalRead(D2) == HIGH)
    {
      digitalWrite(D1,HIGH);
    }
    else
    {
      digitalWrite(D1,LOW);
    }
    

    //Blink LED 
      //on LED
      digitalWrite(D0,HIGH);
    
      //delay 500 ms
      delay(1000);
    
      //off LED
      digitalWrite(D0,LOW);
    
      //delay 500 ms
      delay(1000);
    
    
}

