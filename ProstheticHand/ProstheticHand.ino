#include <Servo.h>

Servo fingers[5];
const int EMG_PIN = A0;

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 5; i++) fingers[i].attach(3 + i);
}

void loop() {
  int emg = analogRead(EMG_PIN);
  int angle = map(emg, 200, 800, 0, 180);
  for (auto &s : fingers) s.write(angle);
  Serial.print("EMG: "); Serial.print(emg); Serial.print(" -> Angle: "); Serial.println(angle);
  delay(20);
}