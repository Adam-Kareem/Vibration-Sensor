#include "display.h"
#include "data_transmit.h"
#include "vibration_Sensor.h"

#include <iostream> // std::cout
#include <string>   // std::string, std::to_string

String f_to_str(float f);

void setup()
{
    oled_setup(); //OLED Setup
    auth_setup(); //WiFi/Firebase Authentication Setup
    MPU6050_setup();
}

void loop()
{
    ui.update(); //Update Screen
    MPU6050_loop();
    display_pos[0] = f_to_str(acc_data);
    display_pos[1] = "test";
    
}

String f_to_str(float f)
{
    char str[16];
    snprintf(str, sizeof(str), "%.2f", f);
    return str;
}