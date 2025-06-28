#include <RF24.h>
#include <SPI.h>
#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "NODE1";

struct State { float x, y, theta; };

void setup() {
  Serial.begin(115200);
  SPI.begin();
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() {
  State me = {0,0,0}, others[5];
  if (radio.available()) {
    radio.read(&others, sizeof(others));
    // Simple cohesion: average positions
    float avgX=0, avgY=0;
    for (int i=0;i<5;i++){ avgX+=others[i].x; avgY+=others[i].y; }
    avgX/=5; avgY/=5;
    // Move toward average
    Serial.print("Move to "); Serial.print(avgX); Serial.print(","); Serial.println(avgY);
  }
  delay(200);
}