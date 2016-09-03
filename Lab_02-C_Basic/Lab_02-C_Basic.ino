/************************
@Since 2016/09/04
@Author AppStack.cc
@Tools Arduino 1.6.11, ESP8266 2.3.0
@Desc Basic c programming
@Note Lab 02
***********************/
#include <stdint.h>
#include <limits.h>

void setup() {
  
  // initialize serial port,  baudrate 9600 bps
  Serial.begin(9600);
  delay(5000);
}

void loop() {
  /* Basic C programming
   * 1. variable
   * 2. condition (if...else...)
   * 3. loop (for, while)
   */
   
  variable_present();
  //loop_for_while();
  //if_else();

}

void loop_for_while()
{
  static uint8_t first = 1;
  uint8_t cnt = 0;
  
  if(first == 0)
  {
    return;
  }
  
  for(cnt = 1; cnt <= 10; cnt++)
  {
    Serial.print(cnt);
    Serial.print(":");
    Serial.println("for loop");
  }

  while(cnt <= 20)
  {
    Serial.print(cnt);
    Serial.print(":");
    Serial.println("while loop");
    cnt++;
  }

  first = 0;

}

void if_else() 
{
  if(Serial.available())
  {
    char ch = (char)Serial.read();
    if(ch >= '0' && ch <= '9')
    {
      Serial.print(ch);
      if(ch % 2 == 0)
      {
        Serial.println(" is even number.");
      }
      else
      {
        Serial.println(" is odd number.");
      }
    }
    else
    {
      Serial.print(ch);Serial.println(" is not a number.");
    }
  
  }

}



void variable_present() 
{

  static uint8_t first = 1;

  int8_t i8 = 0;
  uint8_t ui8 = 0;
  int16_t i16 = 0;
  uint16_t ui16 = 0;
  int32_t i32 = 0;
  uint32_t ui32 = 0;
  
  if(first == 0)
  {
    return;
  }
  
  Serial.println("----------------------------------");
  Serial.print("signed char = ");Serial.print(SCHAR_MIN);Serial.print(",");Serial.println(SCHAR_MAX);
  Serial.print("char = ");Serial.print(CHAR_MIN);Serial.print(",");Serial.println(CHAR_MAX);
  Serial.print("unsigned char = 0,");Serial.println(UCHAR_MAX);
  Serial.println("");
  
  Serial.print("short = ");Serial.print(SHRT_MIN);Serial.print(",");Serial.println(SHRT_MAX);
  Serial.print("unsigned short = 0,");Serial.println(USHRT_MAX);
  Serial.println("");

  Serial.print("int = ");Serial.print(INT_MIN);Serial.print(",");Serial.println(INT_MAX);
  Serial.print("unsigned int = 0,");Serial.println(UINT_MAX);
  Serial.println("");

  Serial.print("long = ");Serial.print(LONG_MIN);Serial.print(",");Serial.println(LONG_MAX);
  Serial.print("unsigned long = 0,");Serial.println(ULONG_MAX);
  Serial.println("");


  first = 0;
  
}






