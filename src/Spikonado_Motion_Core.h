#ifndef MotionCore_h
#define MotionCore_h

#include <Arduino.h>
#include <Wire.h>

#include <SparkFun_BNO08x_Arduino_Library.h>

class MotionCore
{
public:
  BNO08x imu_;
  uint16_t imuTimeBwReports_;
  float accelX_;
  float accelY_;
  float accelZ_;
  uint8_t accelAccuracy_;
  float gyroX_;
  float gyroY_;
  float gyroZ_;
  uint8_t gyroAccuracy_;
  float magX_;
  float magY_;
  float magZ_;
  uint8_t magAccuracy_;
  bool begin(uint16_t imuTimeBwReports = 10);
  bool readIMU();
  void printIMU();
};

#endif  // MotionCore_h
