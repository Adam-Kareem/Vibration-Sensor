#ifndef DISPLAY
#define DISPLAY

#include <heltec.h>
#include "OLEDDisplayUi.h"


//Ui
extern Heltec_ESP32 Heltec;
OLEDDisplayUi ui(Heltec.display);

template <class frame> 
frame displayframe(frame Stat_1,  frame Stat_2, frame Stat_3, frame Stat_4, frame Val_1, frame Val_2, frame Val_3, frame Val_4) 
{ 
  display->setTextAlignment(TEXT_ALIGN_LEFT);
  display->setFont(ArialMT_Plain_10);
  display->drawString(x, y + 5, Stat_1);
  display->drawString(x, y + 15, Stat_2);
  display->drawString(x, y + 25, Stat_3);
  display->drawString(x, y + 35, Stat_4);
  display->drawString(x + 55, y + 5, Val_1);
  display->drawString(x + 55, y + 15, Val_2);
  display->drawString(x + 55, y + 15, Val_3);
  display->drawString(x + 55, y + 25, Val_4);
  display->drawXbm(x + 95, y + 10, 31, 39, hhlogo_bits);

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
  displayframe<std::string,std::string,std::string,std::string,int,int,int,int>("hello", "hello", "hello", "hello", "hello", 1, 2, 3, 4);

}

void drawFrame3(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) //Frame 3: WiFi/Data Status 
{

}

void drawFrame4(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) //Frame 4: Debugging 
{

}

FrameCallback frames[] = {drawFrame1, drawFrame2, drawFrame3, drawFrame4}; //Frame Array 




#endif //DISPLAY