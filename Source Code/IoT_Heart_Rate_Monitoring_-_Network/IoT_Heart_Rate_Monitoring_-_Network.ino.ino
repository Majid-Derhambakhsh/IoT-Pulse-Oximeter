#include <stdio.h>
#include <stdlib.h>
#include <ThingerESP8266.h>

#include "network_chip_conf.h"

/* ~~~~~~~~~~~~~~ Global variable ~~~~~~~~~~~~~~ */
uint8_t g_bpm  = 0;
uint8_t g_spo2 = 0;
uint8_t buffer_save_index = 0;

char str_data[10];
char u_buffer[_BUFF_LENGTH];

/* ~~~~~~~~~~~~~~~ Global Object ~~~~~~~~~~~~~~~ */
ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

/* ~~~~~~~~~~~~~ Function Prototype ~~~~~~~~~~~~ */
void DataControl(char _data);

/* ~~~~~~~~~~~~~~~~~ Functions ~~~~~~~~~~~~~~~~~ */
void setup()
{
  /* Hardware Initialize */
  Serial.begin(_USART_BAUDRATE);
  
  thing.add_wifi(SSID, SSID_PASSWORD);
  
  /* Add value */
  thing["BPM"] >> outputValue(g_bpm);
  
  thing["SpO2"] >> outputValue(g_spo2);
  
}

void loop()
{
  
  thing.handle(); 
  
  if (Serial.available() > 0) /* Check available data */
  {
    
    DataControl(Serial.read());
    
  }
  
}

void DataControl(char _data)
{
  /* ----- Local variable ----- */
  uint8_t index_counter = 0;
  
  /* ----------------------- */
  if(_data == _LINE_FEED) /* Check LF */
  {
    
    u_buffer[buffer_save_index] = '\0';
    
    for (; index_counter < _BUFF_LENGTH; index_counter++)
    {
      
      if (u_buffer[index_counter] == _BPM_DATA) /* Check data type */
      {
        g_bpm = atoi(&u_buffer[index_counter + 1]);
      }
      else if (u_buffer[index_counter] == _SPO2_DATA) /* Check data type */
      {
        g_spo2 = atoi(&u_buffer[index_counter + 1]);
      }
      else{}
      
    }
    
    /* Reset data */
    buffer_save_index = 0;
    
  }
  else
  {
    
    u_buffer[buffer_save_index] = _data;
    
    /* .................. */
    buffer_save_index++;
    
    if (buffer_save_index == _BUFF_LENGTH)
    {
      buffer_save_index = 0;
    }
    
  }
  
}
