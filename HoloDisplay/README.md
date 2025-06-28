# HoloDisplay

## Overview
Persistence-of-vision fan display rendering 3D patterns with rotating LED array.

## Components
- Arduino Uno  
- BLDC motor + driver  
- 32× WS2812 LEDs  
- Rotary encoder for angle sync  

## Wiring
- LED data → pin 6, power 5V, GND common  
- Encoder outputs → D2/D3  

![HoloDisplay Schematic](schematics/HoloDisplay_schematic.png)

## Usage
1. Upload `HoloDisplay.ino`.  
2. Mount LEDs on spinning arm.  
3. Adjust encoder for sync.

## Libraries
- `FastLED`  

## Next Steps
- Add SD card image loading  
- Implement real-time animations  
