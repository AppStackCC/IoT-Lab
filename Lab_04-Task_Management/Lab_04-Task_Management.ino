/************************
@Since 2016/09/04
@Author AppStack.cc
@Tools Arduino 1.6.11, ESP8266 2.3.0
@Desc Task Management
@Note Lab 04
***********************/

void setup() {
  
  // initialize pin D0, D1 as output
  pinMode(D0,OUTPUT);
  pinMode(D1,OUTPUT);
  
  // initialize pin D2 as Input (Try Mode INPUT, INPUT_PULLUP)
  pinMode(D2,INPUT_PULLUP);
  
}

void loop() {

  uint32_t current_Millis = millis();
  static uint32_t previous_Millis = current_Millis;
  static uint8_t toggle_flag = 0;


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
  if((current_Millis - previous_Millis) >= 1000)  //1000ms active
  {
    previous_Millis = current_Millis;
    if(toggle_flag == 0)
    {
      digitalWrite(D0,HIGH);  //ON LED
      toggle_flag = 1;
    }
    else
    {
      digitalWrite(D0,LOW); //OFF LED
      toggle_flag = 0;
    }
  }
    
    
}

