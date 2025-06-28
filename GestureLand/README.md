# GestureLand

## Overview
Hand gesture-controlled drone landing pad using dual ultrasonic sensors for descent commands.

## Components
- Arduino Nano  
- HC-SR04 ultrasonic sensors  
- Bluetooth link to flight controller  

## Wiring
- US1 trig/echo → D2/D3, US2 → D4/D5  
- BT module to D6/D7  

![GestureLand Schematic](schematics/GestureLand_schematic.png)

## Usage
1. Upload `GestureLand.ino`.  
2. Position above landing pad.  
3. Use hand gestures to command drone.

## Libraries
- `NewPing`  
- `SoftwareSerial`  

## Next Steps
- Add gesture calibration  
- Precision landing using image recognition  
