#include <Wire.h>
#include <SPI.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_BMP280.h>
#include <Adafruit_TSL2561_U.h>

/*
  CropHealthDrone
  - Collect multispectral and thermal data
  - Stream to ground station via telemetry
*/

Adafruit_MPU6050 mpu;
Adafruit_BMP280 bmp;
Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.begin();
  bmp.begin(0x76);
  tsl.begin();
}

void loop() {
  sensors_event_t light;
  tsl.getEvent(&light);
  float temp = bmp.readTemperature();
  Serial.print("Light: "); Serial.print(light.light);
  Serial.print(" lux, Temp: "); Serial.print(temp);
  Serial.println(" C");
  delay(1000);
}