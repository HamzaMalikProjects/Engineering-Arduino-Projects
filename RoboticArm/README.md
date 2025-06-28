# RoboticArm

## Overview
High-performance flight controller for quadcopters. Utilizes MPU9250 IMU for orientation sensing and three independent PID loops for roll, pitch, and yaw stabilization.

## Files
- `RoboticArm.ino`: Main flight control firmware.

## Dependencies
- `MPU9250` library by hideakitai
- `PID_v1` library by Brett Beauregard

## Wiring
- Connect MPU9250 SDA/SCL to Arduino SDA/SCL.
- ESC signal wires to pins 2,3,4,5.
- Ground common between battery, ESCs, and Arduino.

## Usage
1. Upload the sketch.
2. Open Serial Monitor at 115200 baud for debug output.
3. Tune PID parameters in the code for stable flight.

## Next Steps
- Integrate barometric altitude hold.
- Add RC receiver input handling.
- Implement fail-safe return-to-home feature.