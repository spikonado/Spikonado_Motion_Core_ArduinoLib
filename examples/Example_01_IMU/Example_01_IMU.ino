#include "Spikonado_ESP32-S3_6_Motor_Driver_IMU_Library.h"

MotorDriverIMU myMDI;

void setup() {
  Serial.begin(115200);
  while(!Serial); // Blocks the program until connected to another device through Serial.

  if (!myMDI.begin()) {
    Serial.println("An error has occured.");
  }
  else {
    Serial.println("Successfully started!");
  }
}

void loop() {
  if (!myMDI.read()) {
    Serial.println("An error has occured.");
  }
  Serial.println("Output in the form accelerometer(x, y, z), gyroscope(x, y, z), magnetometer(x, y, z).");
  Serial.println("The units are m/s^2, rad/s, µT");
  myMDI.print();
}
