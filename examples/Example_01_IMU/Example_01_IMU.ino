#include "Spikonado_Motion_Core.h"

MotionCore myMotionCore;

void setup()
{
  Serial.begin(115200);

  if (!myMotionCore.begin())
  {
    Serial.println("An error has occured.");
  }
  else
  {
    Serial.println("Successfully started!");
    Serial.println(
      "Output in the form accelerometer(x, y, z), gyroscope(x, y, z), magnetometer(x, y, z).");
    Serial.println("The units are m/s^2, rad/s, µT");
  }
}

void loop()
{
  delay(10);  // Time for user to read info

  if (!myMotionCore.readIMU())
  {
    Serial.println("An error has occured.");
  }
  else
  {
    myMotionCore.printIMU();
  }
}
