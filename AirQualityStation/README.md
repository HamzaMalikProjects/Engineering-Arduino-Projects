# AirQualityStation

## Overview
Portable air quality monitor measuring PM2.5, CO₂, and VOCs, with Wi-Fi data upload to ThingSpeak.

## Components
- Arduino MKR1000  
- PMS5003 sensor  
- MH-Z19 CO₂ sensor  
- CCS811 VOC sensor  

## Wiring
- PMS TX/RX → Serial1  
- MH-Z19 TX/RX → Serial2  
- CCS811 SDA/SCL → A4/A5  

![AirQualityStation Schematic](schematics/AirQualityStation_schematic.png)

## Usage
1. Upload `AirQualityStation.ino`.  
2. Configure Wi-Fi credentials.  
3. View data on ThingSpeak.

## Libraries
- `WiFi101`  
- `PMS`  
- `MHZ19`  
- `Adafruit_CCS811`  

## Next Steps
- Add GPS for location tagging  
- Solar-powered enclosure  
