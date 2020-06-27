#ifndef VIB_SENSE
#define VIB_SENSE

// Basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

struct sensor_data 
{
float x;
float y;
float z;
};

sensor_data acc_data;

Adafruit_MPU6050 mpu;

void MPU6050_setup(void)
{
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_16_G);
  mpu.setFilterBandwidth(MPU6050_BAND_260_HZ);
}

void MPU6050_loop()
{

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  acc_data.x = a.acceleration.x;
  acc_data.y = a.acceleration.y;
  acc_data.z = a.acceleration.z;


  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.println("");
}

#endif