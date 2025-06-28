# SwarmBot

## Overview
Decentralized swarm robotics using nRF24L01 radios to implement basic flocking behavior.

## Components
- Arduino Pro Mini  
- nRF24L01+ radio modules  
- IR proximity sensors  
- DC motors + drivers  

## Wiring
- Radio CE → pin 9, CSN → pin 10, MOSI/MISO/SCK → SPI pins  

![SwarmBot Schematic](schematics/SwarmBot_schematic.png)

## Usage
1. Upload `SwarmBot.ino` to all bots.  
2. Power on and observe serial debug.

## Libraries
- `RF24`  
- `SPI`  

## Next Steps
- Add separation and alignment rules  
- Implement obstacle avoidance  
