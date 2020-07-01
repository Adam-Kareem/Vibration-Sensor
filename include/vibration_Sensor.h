//Author : Adam Hussain

#ifndef VIB_SENSE
#define VIB_SENSE

#include <Adafruit_MPU6050.h>
#include <Wire.h>

#define w_to_F 6.283185 //2*pi

Adafruit_MPU6050 mpu;
sensors_event_t a, g, temp;

/*Updates Gyro and frequency values */
class MPU6050_data
{
public:
  float gx, gy, gz; //gyro xyz
  float fx, fy, fz; //frequency xyz
  String Status;    //sensor operational status

  void update()
  {
    mpu.getEvent(&a, &g, &temp);

    gx = abs(g.gyro.x);
    gy = abs(g.gyro.y);
    gz = abs(g.gyro.z);

    fx = g.gyro.x / w_to_F;
    fy = g.gyro.y / w_to_F;
    fz = g.gyro.z / w_to_F;
  }
};

MPU6050_data mpu_data;

/*init MPU sensor*/
void MPU6050_setup(void)
{
  //sensor startup and return status
  mpu.begin();
  !mpu.begin() ? mpu_data.Status = "MPU6050 failure" : mpu_data.Status = "MPU6050 Found!";
  Serial.println(mpu_data.Status);

  mpu.setFilterBandwidth(MPU6050_BAND_260_HZ); //Low pass filter off
  //mpu.setGyroRange(MPU6050_RANGE_250_DEG);   //defaults to 250deg
  mpu.setCycleRate(MPU6050_CYCLE_20_HZ); //sample rate
}

#endif