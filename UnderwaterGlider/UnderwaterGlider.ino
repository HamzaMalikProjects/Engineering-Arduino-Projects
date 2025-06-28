#include <Wire.h>
#include <Servo.h>
#include <MPU6050.h>
#include <Adafruit_MS5803.h>

/*
  Underwater Glider
  - Buoyancy control via servo
  - Depth measurement via MS5803
  - Orientation sensing via MPU6050
*/

Servo ballastServo;
MPU6050 imu;
Adafruit_MS5803 pressureSensor;

const int SERVO_PIN = 9;
const float targetDepth = 5.0; // meters

void setup() {
  Serial.begin(115200);
  Wire.begin();
  ballastServo.attach(SERVO_PIN);
  imu.initialize();
  pressureSensor.begin();
}

void loop() {
  float depth = pressureSensor.readPressure() / 100.0;
  Serial.print("Depth: "); Serial.println(depth);

  if (depth < targetDepth) {
    ballastServo.write(0); // fill ballast to dive
  } else {
    ballastServo.write(90); // release ballast to surface
  }

  delay(1000);
}