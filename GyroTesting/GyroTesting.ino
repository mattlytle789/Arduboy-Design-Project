#include "MPU6050.h"
#include "Adafruit_MPU6050.h"
#include "Adafruit_Sensor.h"
#include "Wire.h"

Adafruit_MPU6050 acceler;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial) {
    
  }
  Serial.println("Start");
  while(!acceler.begin()) {
    Serial.println("No board");
    delay(500);
  }
  acceler.setAccelerometerRange(MPU6050_RANGE_8_G);
  acceler.setGyroRange(MPU6050_RANGE_250_DEG);
  acceler.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  acceler.getEvent(&a, &g, &temp);
  float accelX = a.acceleration.x;
  float accelY = a.acceleration.y;
  float xConst = 0; // used to compare the current acceleration value to 
  float yConst = 0;
  float minTilt = 1.5; // this is the minimum value the board must be tilted to move the snake
  // put your main code here, to run repeatedly:
  if (((accelY-yConst) > minTilt) && (abs(accelX-xConst) < minTilt)) { // tilted left
    Serial.println("Right");
  }
  if (((accelX-xConst) > minTilt) && (abs(accelY-yConst) < minTilt)) { // tilted up
    Serial.println("Down");
  }
  if (((accelY-yConst) < -minTilt) && (abs(accelX-xConst) < minTilt)) { // tilt right
    Serial.println("Left");
  }
  if (((accelX-xConst) < -minTilt) && (abs(accelY-yConst) < minTilt)) { // tilt down
    Serial.println("Up");
  }
  if ((accelX>-minTilt) && (accelX<minTilt) && (accelY>-minTilt) && (accelY<minTilt)) { // continuing in same direction if board is not tilted

  }
  /*Serial.print("Z = ");
  Serial.println(g.gyro.z);*/
  delay(10);
}
