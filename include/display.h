//Author : Adam Hussain

#ifndef DISPLAY_ES32
#define DISPLAY_ES32

#include "heltec.h"
#include "OLEDDisplayUi.h"
#define framecount 1

//Ui initilisation
extern Heltec_ESP32 Heltec;
OLEDDisplayUi ui(Heltec.display);

String display_pos[3]; 

/*sets out strings within given frame */

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

/*display init*/
void oled_setup()
{
  //Oled Setup
  Heltec.begin(true /*DisplayEnable Enable*/, false /*LoRa Disable*/, false /*Serial Enable*/); //Oled Enable
  ui.setTargetFPS(30);                                                                          //Refresh Rate
  ui.init();                                                                                    //Initialise
  Heltec.display->flipScreenVertically();
  Heltec.display->setFont(ArialMT_Plain_10);
  display_pos[0] = "XOR sytems";
  ui.setFrames(frames, framecount);
  Heltec.display->flipScreenVertically();
}

/*Displays data on OLED*/
class MPU6050_frame
{
    public:
    String f_to_str(float f)
    {
        char str[16];
        snprintf(str, sizeof(str), "%.2f", f);
        return str;
    }

    void display(float x, float y, float z, String unit)
    {
        display_pos[0] = "MPU6050 gyro values";
        display_pos[1] = "x axis: " + f_to_str(x) + unit;
        display_pos[2] = "y axis: " + f_to_str(y) + unit;
        display_pos[3] = "z axis: " + f_to_str(z) + unit;
        ui.update();
    }
};

#endif //DISPLAY_ES32