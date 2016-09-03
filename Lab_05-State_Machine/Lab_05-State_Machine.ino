/************************
@Since 2016/09/04
@Author AppStack.cc
@Tools Arduino 1.6.11, ESP8266 2.3.0
@Desc State Machine
@Note Lab 00
***********************/

#include <stdint.h>
#include <stdbool.h>

#define _MAX_TEXT_BUFFER_ 50

enum
{
  STATE_1 = 1,
  STATE_2,
  STATE_3,
};

char TEXT_BUEFFER[_MAX_TEXT_BUFFER_];
uint8_t TEXT_BUEFFER_CNT = 0;
uint8_t STATE = STATE_1;


void setup()
{
  Serial.begin(115200);
  memset(TEXT_BUEFFER,0,_MAX_TEXT_BUFFER_);
}


void process_serial(char data,uint8_t *state,char *buffer,uint8_t *buffer_cnt)
{
  switch(*state)
  {
   case STATE_1:
   {
     if(data == '<')
     {
       *state = STATE_2;
     }
   }
   break;
   case STATE_2:
   {
     if(data == '<')
     {
        memset(buffer,0,_MAX_TEXT_BUFFER_);
        *buffer_cnt = 0;
       *state = STATE_3;
     }
     else if(data == '>')
     {
       if(*buffer_cnt > 0)
       {
        Serial.print("Text : ");
        Serial.println(buffer);
       }
      memset(buffer,0,_MAX_TEXT_BUFFER_);
      *buffer_cnt = 0;
      *state = STATE_1;
     }
     else
     {
      if(*buffer_cnt < _MAX_TEXT_BUFFER_)
      {
        buffer[(*buffer_cnt)++] = data;
      } 
     }
   }
   break;
   case STATE_3:
   {
     if(data == '>')
     {
       *state = STATE_1;
     }
     else if(data == '<')
     {
        memset(buffer,0,_MAX_TEXT_BUFFER_);
        *buffer_cnt = 0;
     }
     else
     {
        buffer[(*buffer_cnt)++] = data;
       *state = STATE_2;
     }
   }
   break;
  }
}

void loop()
{
  if(Serial.available()> 0)
  {
    process_serial(Serial.read(),&STATE,TEXT_BUEFFER,&TEXT_BUEFFER_CNT);
  }
}
