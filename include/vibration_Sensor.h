#ifndef VIB_SENSE
#define VIB_SENSE

// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
//#include <Adafruit_Sensor.h>
#include <Wire.h>

#define w_to_F 6.283185

struct g_data 
{
float x;
float y;
float z;
};

struct f_data 
{
float x;
float y;
float z;
};

g_data gyro_data;
f_data freq_data;

Adafruit_MPU6050 mpu;

/* Create new sensor events */
sensors_event_t a, g, temp;

void MPU6050_setup(void)
{
  mpu.begin();

   // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_2_G);
  mpu.setFilterBandwidth(MPU6050_BAND_260_HZ);
  mpu.setCycleRate(MPU6050_CYCLE_20_HZ);
}

void MPU6050_loop()
{

  /* Get new sensor events with the readings */

  sensors_event_t a;
  mpu.getEvent(&a, &g, &temp);
  
  gyro_data.x = abs(g.gyro.x);
  gyro_data.y = abs(g.gyro.y);
  gyro_data.z = abs(g.gyro.z);

  freq_data.x = g.gyro.x/w_to_F;
  freq_data.y = g.gyro.y/w_to_F;
  freq_data.z = g.gyro.z/w_to_F;
}

#endif