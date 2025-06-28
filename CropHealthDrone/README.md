# CropHealthDrone

## Overview
Collects light (NDVI proxy) and temperature data for crop health analysis using an Arduino-powered drone.

## Components
- Arduino Nano  
- Adafruit MPU6050 IMU  
- Adafruit BMP280 pressure & temperature sensor  
- Adafruit TSL2561 light sensor  
- Telemetry module (e.g., 433MHz radio)

## Wiring
- MPU6050 SDA → A4, SCL → A5  
- BMP280 SDA → A4, SCL → A5  
- TSL2561 SDA → A4, SCL → A5  

![CropHealthDrone Schematic](schematics/CropHealthDrone_schematic.png)

## Usage
1. Upload `CropHealthDrone.ino`.  
2. Open Serial Monitor at 115200 baud.  
3. Mount on drone for data collection.

## Libraries
- `Adafruit_MPU6050`  
- `Adafruit_BMP280`  
- `Adafruit_TSL2561_U`  

## Next Steps
- Integrate NDVI calculation  
- Add GPS tagging of data  
