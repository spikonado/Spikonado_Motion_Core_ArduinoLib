#include "Spikonado_Motion_Core.h"

bool MotionCore::begin(uint16_t imuTimeBwReports)
{
  imuTimeBwReports_ = imuTimeBwReports;
  Wire.begin();
  if (!(imu_.begin(0x4B, Wire, 18, 17) && imu_.enableAccelerometer(imuTimeBwReports_) &&
        imu_.enableGyro(imuTimeBwReports_) && imu_.enableMagnetometer(imuTimeBwReports_)))
  {
    return false;
  }

  return true;
}

bool MotionCore::readIMU()
{
  if (imu_.wasReset())
  {
    if (!(imu_.enableAccelerometer(imuTimeBwReports_) && imu_.enableGyro(imuTimeBwReports_) &&
          imu_.enableMagnetometer(imuTimeBwReports_)))
    {
      return false;
    }
  }
  if (imu_.getSensorEvent() == true)
  {
    if (imu_.getSensorEventID() == SENSOR_REPORTID_ACCELEROMETER)
    {
      accelX_ = imu_.getAccelX();
      accelY_ = imu_.getAccelY();
      accelZ_ = imu_.getAccelZ();
      accelAccuracy_ = imu_.getAccelAccuracy();
    }
    else if (imu_.getSensorEventID() == SENSOR_REPORTID_GYROSCOPE_CALIBRATED)
    {
      gyroX_ = imu_.getGyroX();
      gyroY_ = imu_.getGyroY();
      gyroZ_ = imu_.getGyroZ();
      gyroAccuracy_ = imu_.getGyroAccuracy();
    }
    else if (imu_.getSensorEventID() == SENSOR_REPORTID_MAGNETIC_FIELD)
    {
      magX_ = imu_.getMagX();
      magY_ = imu_.getMagY();
      magZ_ = imu_.getMagZ();
      magAccuracy_ = imu_.getMagAccuracy();
    }
  };
  return true;
}

void MotionCore::printIMU()
{
  Serial.print(accelX_, 2);
  Serial.print(" ");
  Serial.print(accelY_, 2);
  Serial.print(" ");
  Serial.print(accelZ_, 2);
  Serial.print(" ");
  Serial.print(gyroX_, 2);
  Serial.print(" ");
  Serial.print(gyroY_, 2);
  Serial.print(" ");
  Serial.print(gyroZ_, 2);
  Serial.print(" ");
  Serial.print(magX_, 2);
  Serial.print(" ");
  Serial.print(magY_, 2);
  Serial.print(" ");
  Serial.print(magZ_, 2);
  Serial.print("\n");
}
