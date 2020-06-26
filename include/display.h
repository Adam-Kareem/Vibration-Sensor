#ifndef DISPLAY
#define DISPLAY

//Display Header files
#include "heltec.h"
#include "OLEDDisplayUi.h"
#include "xor_logo.h" 

#define framecount 2

//Ui initilisation
extern Heltec_ESP32 Heltec;
OLEDDisplayUi ui(Heltec.display);
String display_pos[7];

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
    display->drawString(x, y + 5, display_pos[0]);
    display->drawString(x, y + 15, display_pos[2]);
    display->drawString(x, y + 25, display_pos[4]);
    display->drawString(x, y + 35, display_pos[6]);
    display->drawString(x + 55, y + 5, display_pos[1]);
    display->drawString(x + 55, y + 15, display_pos[3]);
    display->drawString(x + 55, y + 15, display_pos[5]);
    display->drawString(x + 55, y + 25, display_pos[7]);
  }

FrameCallback frames[] = {drawFrame2,drawFrame2}; //Frame Array 

void oled_setup()
{
  //Oled Setup 
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, false /*Serial Enable*/); //Oled Enable
  ui.setTargetFPS(30); //Refresh Rate 
  ui.init(); //Initialise 
  ui.setIndicatorPosition(BOTTOM); 
  ui.setIndicatorDirection(LEFT_RIGHT); 
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setFrames(frames, framecount); 
  Heltec.display->flipScreenVertically();
}

#endif //DISPLAY