#include <AccelStepper.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>

/*
  FilamentMonitor
  - Measures filament diameter via analog sensor
  - Adjusts extruder speed accordingly
  - Displays data on OLED
*/

#define SENSOR_PIN A0
#define OLED_RESET -1
#define STEPPER_STEP 3
#define STEPPER_DIR 4

AccelStepper extruder(AccelStepper::DRIVER, STEPPER_STEP, STEPPER_DIR);
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);

const float nominalDiameter = 1.75;

void setup() {
  Serial.begin(115200);
  extruder.setMaxSpeed(1000);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  int raw = analogRead(SENSOR_PIN);
  float diameter = map(raw, 0, 1023, 0, 5); // convert to mm
  float speed = 100 * (nominalDiameter / diameter);
  extruder.setSpeed(speed);
  extruder.runSpeed();

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Dia: "); display.print(diameter);
  display.print("mm");
  display.setCursor(0,10);
  display.print("Speed: "); display.print(speed);
  display.display();

  delay(200);
}