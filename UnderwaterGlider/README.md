# UnderwaterGlider

## Overview
Buoyancy-driven underwater glider controlled by Arduino Pro Mini. Adjusts ballast via servo for autonomous dives and surfaces.

## Components
- Arduino Pro Mini  
- Waterproof servo (e.g., Hitec HS-65)  
- MPU-6050 IMU  
- MS5803 pressure sensor  
- LiPo battery + charger  

## Wiring
- Servo signal to pin 9; power from 5V and GND.  
- MPU-6050: SDA → A4, SCL → A5, VCC → 3.3V, GND → GND.  
- MS5803: SDA → A4, SCL → A5, VCC → 3.3V, GND → GND.

![Glider Schematic](schematics/UnderwaterGlider_schematic.png)

## Usage
1. Upload `UnderwaterGlider.ino` using 5V Arduino Pro Mini.  
2. Monitor depth via Serial at 115200 baud.  
3. Adjust `targetDepth` in code for desired dive depth.

## Libraries
- `MPU6050` by Jeff Rowberg  
- `Adafruit_MS5803`  

## Next Steps
- Implement PID control for smoother depth transitions.  
- Add telemetry via acoustic modem.  
