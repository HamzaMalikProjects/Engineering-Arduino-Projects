# FilamentMonitor

## Overview
Real-time filament diameter monitor that adjusts extruder speed to maintain consistent extrusion. Displays measurements on an OLED.

## Components
- Arduino Mega  
- Laser triangulation or analog diameter sensor  
- AccelStepper driver + extruder motor  
- SSD1306 OLED display (128x32)  

## Wiring
- Sensor output → A0  
- Stepper STEP → pin 3, DIR → pin 4  
- OLED SDA → A4, SCL → A5, VCC → 3.3V, GND → GND  

![FilamentMonitor Schematic](schematics/FilamentMonitor_schematic.png)

## Usage
1. Upload `FilamentMonitor.ino`.  
2. Calibrate sensor mapping raw values to mm.  
3. Monitor serial for debug.

## Libraries
- `AccelStepper`  
- `Adafruit_SSD1306`  
- `Adafruit_GFX`  

## Next Steps
- Integrate with OctoPrint plugin.  
- Implement feed rate smoothing algorithm.  
