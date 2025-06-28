#include <WiFi101.h>
#include <PMS.h>
#include <MHZ19.h>
#include <Adafruit_CCS811.h>

PMS pms(&Serial1);
MHZ19 co2;
Adafruit_CCS811 voc;

void setup() {
  Serial.begin(115200);
  WiFi.begin("SSID", "PASS");
  pms.begin();
  co2.begin();
  voc.begin();
}

void loop() {
  int pm = pms.read();
  int co2ppm = co2.getCO2();
  float vocVal = voc.geteCO2();
  Serial.print("PM2.5: "); Serial.print(pm);
  Serial.print(" CO2: "); Serial.print(co2ppm);
  Serial.print(" VOC: "); Serial.println(vocVal);
  delay(60000);
}