#ifndef DISPLAY
#define DISPLAY

//Display Header files
#include "heltec.h"
#include "OLEDDisplayUi.h"
#include "xor_logo.h" 

//Ui initilisation
extern Heltec_ESP32 Heltec;
OLEDDisplayUi ui(Heltec.display);
String lineStatef1[7];

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
 // display->drawXbm(x + 95, y + 10, 31, 39, logo_bits); //XOR logo, image needs rectified
}
 void drawFrame2(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) 
  {
    display->setTextAlignment(TEXT_ALIGN_LEFT);
    display->setFont(ArialMT_Plain_10);
    display->drawString(x, y + 5, lineStatef1[0]);
    display->drawString(x, y + 15, lineStatef1[2]);
    display->drawString(x, y + 25, lineStatef1[4]);
    display->drawString(x, y + 35, lineStatef1[6]);
    display->drawString(x + 55, y + 5, lineStatef1[1]);
    display->drawString(x + 55, y + 15, lineStatef1[3]);
    display->drawString(x + 55, y + 15, lineStatef1[5]);
    display->drawString(x + 55, y + 25, lineStatef1[7]);
  }

#endif //DISPLAY