#include <NewPing.h>
#include <SoftwareSerial.h>

NewPing us1(2,3,200), us2(4,5,200);
SoftwareSerial link(6,7);

void setup() {
  Serial.begin(115200);
  link.begin(57600);
}

void loop() {
  int d1 = us1.ping_cm();
  int d2 = us2.ping_cm();
  if (d1 < 20 && d2 < 20) link.println("LAND");
  else link.println("HOLD");
  delay(100);
}