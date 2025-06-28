#include <SoftwareSerial.h>

SoftwareSerial btSerial(2, 3);
const int MOTOR_PIN = 6;

void setup() {
  Serial.begin(115200);
  btSerial.begin(57600);
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() {
  if (btSerial.available()) {
    int level = btSerial.read(); // EEG attention level
    if (level > 150) analogWrite(MOTOR_PIN, 255);
    else analogWrite(MOTOR_PIN, 0);
    Serial.print("EEG Level: "); Serial.println(level);
  }
  delay(20);
}