
/* Include */
#include <SPI.h>
#include <Wire.h>
#include <stdio.h>
#include <MCUFRIEND_kbv.h>

#include "lcd_conf.h"
#include "main_mcu_conf.h"
#include "content_location_conf.h"
#include "MAX30100_PulseOximeter.h"
#include "Adafruit_GFX.h"

/* ~~~~~~~~~~~~~~~~ Global variable ~~~~~~~~~~~~~~~~ */
int16_t bpm = 0;
int16_t spo2 = 0;

uint32_t tsLastReport = 0;

char value_str[5];
char display_str[10];

/* ~~~~~~~~~~~~~~~~ Global object ~~~~~~~~~~~~~~~~ */
PulseOximeter pox_sensor;
MCUFRIEND_kbv tft_lcd;

/* ~~~~~~~~~~~~~~~~~~ Functions ~~~~~~~~~~~~~~~~~~ */

void setup()
{
  /* ------------ Local variable ------------ */
  uint16_t ID;
  
  /* -------- Initialize Serial Port -------- */
  Serial.begin(_USART_BAUDRATE);
  
  /* ------- Initialize PulseOximeter ------- */
  while (!pox_sensor.begin()){}
  
  /* ---------- TFT LCD Initialize ---------- */
  
  ID = tft_lcd.readID();
  
  if (ID == 0xD3D3) ID = 0x9481; // write-only shield
  
  tft_lcd.begin(ID);
  
  tft_lcd.fillScreen(WHITE);

  tft_lcd.setCursor(_MESSAGE_LABEL_X, _MESSAGE_LABEL_Y);
  tft_lcd.setTextSize(_MESSAGE_SIZE);
  tft_lcd.setTextColor(GREEN, WHITE);
  tft_lcd.println("System Initialized.");

  delay(SHOW_TIME);
  
  tft_lcd.fillScreen(WHITE);

  tft_lcd.setCursor(_BPM_LABEL_X, _BPM_LABEL_Y);
  tft_lcd.setTextSize(_LABEL_SIZE);
  tft_lcd.setTextColor(RED, WHITE);
  tft_lcd.println("BPM:");
  
  tft_lcd.setCursor(_SPO2_LABEL_X, _SPO2_LABEL_Y);
  tft_lcd.setTextSize(_LABEL_SIZE);
  tft_lcd.setTextColor(BLUE, WHITE);
  tft_lcd.println("SpO2:");
  
  /* ------ Reinitialize PulseOximeter ------ */
  while (!pox_sensor.begin()){}
  
}

void loop()
{
  
  pox_sensor.update();
  
  if (millis() - tsLastReport > REPORTING_PERIOD_MS)
  {
    
    bpm = pox_sensor.getHeartRate();
    spo2 = pox_sensor.getSpO2();
    
    /* ------------------------- */
    Serial.print('B');
    Serial.print(bpm);
    Serial.print('\x0A');
    
    sprintf(display_str,"%u    ", bpm);
    
    tft_lcd.setCursor(_BPM_VALUE_X, _BPM_VALUE_Y);
    tft_lcd.setTextSize(_CONTENT_SIZE);
    tft_lcd.setTextColor(BLACK, WHITE);
    tft_lcd.println(display_str);
    
    Serial.print('S');
    Serial.print(spo2);
    Serial.print('\x0A');
    
    sprintf(display_str,"%u    ", spo2);
    
    tft_lcd.setCursor(_SPO2_VALUE_X, _SPO2_VALUE_Y);
    tft_lcd.setTextSize(_CONTENT_SIZE);
    tft_lcd.setTextColor(BLACK, WHITE);
    tft_lcd.println(display_str);
    
    tsLastReport = millis();
  }
}
