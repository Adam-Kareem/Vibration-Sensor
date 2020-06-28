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

    display_pos[0] = "x axis: " + f_to_str(gyro_data.x) + "  rad/s";
    display_pos[1] = "y axis: " + f_to_str(gyro_data.y) + "  rad/s";
    display_pos[2] = "z axis: " + f_to_str(gyro_data.z) + "  rad/s";
    Firebase.pushFloat(firebaseData,"/Gyro/x axis",gyro_data.x);
    Firebase.pushFloat(firebaseData,"/Gyro/y axis",gyro_data.y);
    Firebase.pushFloat(firebaseData,"/Gyro/z axis",gyro_data.z);
    Firebase.pushFloat(firebaseData,"/Freq/x axis",freq_data.x);
    Firebase.pushFloat(firebaseData,"/Freq/y axis",freq_data.y);
    Firebase.pushFloat(firebaseData,"/Freq/z axis",freq_data.z);
    Firebase.pushTimestamp(firebaseData, "datA/Timestamp");
}

String f_to_str(float f)
{
    char str[16];
    snprintf(str, sizeof(str), "%.2f", f);
    return str;
}