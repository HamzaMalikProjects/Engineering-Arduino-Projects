# VoiceAI

## Overview
BLE voice assistant interface using Arduino Nano 33 BLE Sense. Receives commands from an external AI engine over BLE to control home devices via relay.

## Components
- Arduino Nano 33 BLE Sense  
- Relay module  
- BLE gateway (e.g., Raspberry Pi)  
- Microphone & AI engine on gateway  

## Wiring
- Relay IN → pin 7, VCC → 5V, GND → GND.

![VoiceAI Schematic](schematics/VoiceAI_schematic.png)

## Usage
1. Upload `VoiceAI.ino`.  
2. Pair Arduino as BLE peripheral.  
3. Send "ON"/"OFF" commands from AI gateway.

## Libraries
- `ArduinoBLE`

## Next Steps
- Add onboard wake word detection.  
- Secure BLE communication with passkeys.  
