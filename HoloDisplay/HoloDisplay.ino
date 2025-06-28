#include <FastLED.h>
#define NUM_LEDS 32
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  static int angle = 0;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV((i*10 + angle) % 255, 255, 255);
  }
  FastLED.show();
  angle++;
  delay(10);
}