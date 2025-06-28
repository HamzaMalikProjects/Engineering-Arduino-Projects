# BCICar

## Overview
Brain–Computer Interface car control using EEG data from OpenBCI Ganglion over Bluetooth.

## Components
- Arduino Uno  
- HC-05 Bluetooth module  
- OpenBCI Ganglion (EEG)  
- Motor driver + DC motor  

## Wiring
- HC-05 TX → pin 2, RX → pin 3  
- Motor driver input → pin 6  

![BCICar Schematic](schematics/BCICar_schematic.png)

## Usage
1. Upload `BCICar.ino`.  
2. Pair HC-05 with EEG device.  
3. Drive car by focusing (attention level > threshold).

## Libraries
- `SoftwareSerial`  

## Next Steps
- Calibrate attention thresholds  
- Implement turn-by-thought controls  
