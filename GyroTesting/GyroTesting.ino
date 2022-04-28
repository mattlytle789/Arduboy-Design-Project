#include "MPU6050.h"
#include "Adafruit_MPU6050.h"
#include "Adafruit_Sensor.h"
#include "Wire.h"

Adafruit_MPU6050 gyro;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial) {
    
  }
  Serial.println("Start");
  while(!gyro.begin()) {
    Serial.println("No board");
    delay(500);
  }
  gyro.setGyroRange(MPU6050_RANGE_250_DEG);
  gyro.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  gyro.getEvent(&a, &g, &temp);
  // put your main code here, to run repeatedly:
  Serial.print("X = ");
  Serial.print(a.acceleration.x);
  Serial.print("  Y = ");
  Serial.println(a.acceleration.y);
  /*Serial.print("Z = ");
  Serial.println(g.gyro.z);*/
  delay(1000);
}
