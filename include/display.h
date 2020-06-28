#ifndef DISPLAY
#define DISPLAY

//Display Header files
#include "heltec.h"
#include "OLEDDisplayUi.h"

#define framecount 1

//Ui initilisation
extern Heltec_ESP32 Heltec;
OLEDDisplayUi ui(Heltec.display);
String display_pos[3];
 
void drawFrame1(OLEDDisplay *display, OLEDDisplayUiState *state, int16_t x, int16_t y) 
  {
    display->setTextAlignment(TEXT_ALIGN_LEFT);
    display->setFont(ArialMT_Plain_10);
    display->drawString(x, y + 5, display_pos[0]);
    display->drawString(x, y + 15, display_pos[1]);
    display->drawString(x, y + 25, display_pos[2]);
    display->drawString(x, y + 35, display_pos[3]);
  }

FrameCallback frames[] = {drawFrame1}; //Frame Array 

void oled_setup()
{
  //Oled Setup 
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, false /*Serial Enable*/); //Oled Enable
  ui.setTargetFPS(60); //Refresh Rate 
  ui.init(); //Initialise 
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);
  display_pos[0] = "XOR sytems";
  ui.setFrames(frames, framecount); 
  Heltec.display->flipScreenVertically();
}

#endif //DISPLAY