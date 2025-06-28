#include <Wire.h>
#include <MPU9250.h>
#include <PID_v1.h>

/*
  Drone Flight Controller
  - Sensor fusion with MPU9250
  - PID stabilization for roll, pitch, yaw
*/

const int ESC_PINS[4] = {2, 3, 4, 5};
MPU9250 imu(Wire, 0x68);

// PID controllers for roll, pitch, yaw
double inputVals[3], outputVals[3], setpoints[3] = {0, 0, 0};
PID pids[3] = {
  PID(&inputVals[0], &outputVals[0], &setpoints[0], 1.2, 0.01, 0.05, DIRECT),
  PID(&inputVals[1], &outputVals[1], &setpoints[1], 1.2, 0.01, 0.05, DIRECT),
  PID(&inputVals[2], &outputVals[2], &setpoints[2], 1.0, 0.005, 0.03, DIRECT)
};

void setup() {
  Serial.begin(115200);
  Wire.begin();
  imu.begin();
  for (auto &pid : pids) pid.SetMode(AUTOMATIC);
  for (int pin : ESC_PINS) pinMode(pin, OUTPUT);
}

void loop() {
  imu.readSensor();
  inputVals[0] = imu.getRoll();
  inputVals[1] = imu.getPitch();
  inputVals[2] = imu.getYaw();

  for (auto &pid : pids) pid.Compute();

  for (int i = 0; i < 3; i++) {
    analogWrite(ESC_PINS[i], constrain(1500 + outputVals[i], 1000, 2000));
  }
  analogWrite(ESC_PINS[3], 1500); // constant throttle for testing

  delay(10);
}