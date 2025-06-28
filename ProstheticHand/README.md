# ProstheticHand

## Overview
EMG-controlled prosthetic hand using MyoWare sensors and servo-actuated fingers with haptic feedback.

## Components
- Arduino Due  
- MyoWare EMG sensor  
- 5× micro servos  
- Vibration motor  

## Wiring
- EMG sensor out → A0  
- Servos to pins 3–7, power 5V  

![ProstheticHand Schematic](schematics/ProstheticHand_schematic.png)

## Usage
1. Upload `ProstheticHand.ino`.  
2. Calibrate EMG thresholds.  
3. Test grip control.

## Libraries
- `Servo`  

## Next Steps
- Integrate haptic feedback based on grip force  
- Add gesture recognition  
