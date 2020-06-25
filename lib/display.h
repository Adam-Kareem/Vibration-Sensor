#ifndef DISPLAY
#define DISPLAY

#include "Arduino.h"
#include <heltec.h>
#include <OLEDDisplayUi.h>

//Ui
extern Heltec_ESP32 Heltec;
OLEDDisplayUi ui(Heltec.display);

template <typename frame> 
frame displayframe(frame Stat_1,  frame Stat_2, frame Stat_3, frame Stat_4, frame Val_1, frame Val_2, frame Val_3, frame Val_4) 
{ 


   return 0; 
} 


void msOverlay(OLEDDisplay *display, OLEDDisplayUiState *state) //Defines times between frames 
{
  display->setTextAlignment(TEXT_ALIGN_RIGHT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(128, 0, String(millis()));
}

void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) //Frame 1: Welcome 
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_16);
  display->drawString(x + 20, y + 10, "XOR");
  display->drawString(x + 20, y + 25, "Systems");
  display->drawXbm(x + 95, y + 10, 31, 39, hhlogo_bits);
}

void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) //Frame 2: Sensor Values 
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(x, y + 5, "Light (Lx):");
  display->drawString(x + 51, y + 5, SLux);
  display->drawString(x, y + 15, "Temp (C):");
  display->drawString(x + 51, y + 15, Stemp);
  display->drawString(x, y + 25, "RH (%):");
  display->drawString(x + 51, y + 25, Shumidity);
  display->drawString(x, y + 35, "C02 (ppm):");
  display->drawString(x + 51, y + 35, SC02);
  display->drawXbm(x + 95, y + 10, 31, 39, hhlogo_bits);
}

void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) //Frame 3: WiFi/Data Status 
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(x, y + 5, Wi_fi_Output);
  display->drawString(x, y + 15, ssid);
  display->drawString(x, y + 25, Data_Output);
  display->drawXbm(x + 95, y + 10, 31, 39, hhlogo_bits);
}

void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) //Frame 4: Debugging 
{
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(x, y + 5, "WiFi_Poll:");
  display->drawString(x, y + 15, "Data_Poll:");
  display->drawString(x, y + 25, "TS_Poll:");
  display->drawString(x, y + 35, "TS Code:");
  display->drawString(x + 55, y + 5, SWiFi_Poll);
  display->drawString(x + 55, y + 15, SSensor_Poll);
  display->drawString(x + 55, y + 15, STS_Poll);
  display->drawString(x + 55, y + 25, STS_Status);
  display->drawXbm(x + 95, y + 10, 31, 39, hhlogo_bits);
}

FrameCallback frames[] = {drawFrame1, drawFrame2, drawFrame3, drawFrame4}; //Frame Array 




#endif //DISPLAY