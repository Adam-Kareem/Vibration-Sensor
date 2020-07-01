//Author : Adam Hussain

#include "display.h"
#include "data_transmit.h"
#include "vibration_Sensor.h"

#include <iostream>
#include <string>  

#define ESP32_CORE_0 0
#define ESP32_CORE_1 1
 
TaskHandle_t Task1;
TaskHandle_t Task2;
TaskHandle_t Task3;

MPU6050_frame g_frame;
F_REST Firebase_gyro;
F_REST Firebase_freq;

void Task1code(void *parameter);
void Task2code(void *parameter);
//void Task3code(void *parameter);

void setup()
{
  Serial.begin(115200);
  oled_setup();    //OLED Setup
  auth_setup();    //WiFi & Firebase Authentication Setup
  MPU6050_setup(); //MPU init

  xTaskCreatePinnedToCore(Task1code, "MPU_Update", 2048, NULL, 2, &Task1, ESP32_CORE_1);

  xTaskCreatePinnedToCore(Task2code, "Firebase_Rest", 6000, NULL, 1, &Task2, ESP32_CORE_1);

  //xTaskCreatePinnedToCore(Task3code,"Display",60000,NULL,0,&Task3,ESP32_CORE_0);
}

void loop()
{
}

void Task1code(void *parameter)
{
  for (;;)
  {
    unsigned long start = millis();
    mpu_data.update();
    Serial.println("Task1 running on core ");
    Serial.println(xPortGetCoreID());
    Serial.println("Runtime(ms) = ");
    Serial.println(+(millis() - start));
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void Task2code(void *parameter)
{
  for (;;)
  {
    unsigned long start = millis();
    Firebase_gyro.Push("Gyro", mpu_data.gx, mpu_data.gy, mpu_data.gz);
    Firebase_freq.Push("Freq", mpu_data.fx, mpu_data.fy, mpu_data.fz);
    Serial.println("Task2 running on core ");
    Serial.println(xPortGetCoreID());
    Serial.println("Runtime(ms) = ");
    Serial.println(+(millis() - start));
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
/*
void Task3code(void *parameter)
{
  for (;;)
  {
    unsigned long start = millis();
    g_frame.display(mpu_data.gx, mpu_data.gy, mpu_data.gz, "  rad/s");
    Serial.println("Task3 running on core ");
    Serial.println(xPortGetCoreID());
    Serial.println("Runtime(ms) = ");
    Serial.println(+(millis() - start));
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}*/
