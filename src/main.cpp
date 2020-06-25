#include "display.h"

void setup()
{
  
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, false /*Serial Enable*/); //Oled Enable
  
  ui.setTargetFPS(30); //Refresh Rate 
  ui.init(); //Initialise 
  ui.setIndicatorPosition(BOTTOM); //Indicator = Framecallback Status 
  ui.setIndicatorDirection(LEFT_RIGHT); 
  ui.setFrameAnimation(SLIDE_LEFT);
  ui.setFrames(frames, 4); 
  
  Heltec.display->flipScreenVertically();
}

void loop()
{
    ui.update(); //Update Screen 
}