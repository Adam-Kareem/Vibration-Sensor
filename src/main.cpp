#include "display.h"
#include "data_transmit.h"
#include "vibration_Sensor.h"

#include <iostream> // std::cout
#include <string>   // std::string, std::to_string

String f_to_str(float f);

void setup()
{
    Serial.begin(115200);
    oled_setup(); //OLED Setup
    auth_setup(); //WiFi & Firebase Authentication Setup
    MPU6050_setup();
}

void loop()
{
    ui.update(); //Update Screen
    MPU6050_loop();
    display_pos[0] = "x axis: " + f_to_str(acc_data.x) + "  m/s²";
    display_pos[1] = "y axis: " + f_to_str(acc_data.y) + "  m/s²";
    display_pos[2] = "z axis: " + f_to_str(acc_data.z) + "  m/s²";
    Firebase.pushFloat(firebaseData,"/Acc/x axis",acc_data.x);
    Firebase.pushFloat(firebaseData,"/Acc/y axis",acc_data.y);
    Firebase.pushFloat(firebaseData,"/Acc/z axis",acc_data.z);
    Firebase.pushTimestamp(firebaseData, "/Acc/Timestamp");
}

String f_to_str(float f)
{
    char str[16];
    snprintf(str, sizeof(str), "%.2f", f);
    return str;
}