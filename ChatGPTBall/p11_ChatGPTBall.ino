#include <SPI.h>
#include <RH_ASK.h>

RH_ASK driver;

const int motorPin1 = 9;  // Motor 1 connected to pin 9
const int motorPin2 = 10; // Motor 2 connected to pin 10
const int motorPin3 = 11; // Motor 3 connected to pin 11
const int motorPin4 = 12; // Motor 4 connected to pin 12
const int weaponPin = 13; // Weapon connected to pin 13

void setup() {
  // Initialize motor pins as output
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(weaponPin, OUTPUT);

  // Initialize RF receiver
  if (!driver.init()) {
    Serial.println("RF init failed");
    while (1);
  }

  Serial.begin(9600);
}

void loop() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    int command = atoi((char*)buf);
    Serial.print("Received: ");
    Serial.println(command);

    switch(command) {
      case 1:
        // Command to move forward
        analogWrite(motorPin1, 255); // Full speed forward
        analogWrite(motorPin2, 255); // Full speed forward
        analogWrite(motorPin3, 255); // Full speed forward
        analogWrite(motorPin4, 255); // Full speed forward
        break;
      case 2:
        // Command to move backward
        analogWrite(motorPin1, 0);   // Full speed backward
        analogWrite(motorPin2, 0);   // Full speed backward
        analogWrite(motorPin3, 0);   // Full speed backward
        analogWrite(motorPin4, 0);   // Full speed backward
        break;
      case 3:
        // Command to activate weapon
        digitalWrite(weaponPin, HIGH); // Activate weapon
        delay(1000);                   // Activate for 1 second
        digitalWrite(weaponPin, LOW);  // Deactivate weapon
        break;
      default:
        // Stop all motors
        analogWrite(motorPin1, 128);  // Stop
        analogWrite(motorPin2, 128);  // Stop
        analogWrite(motorPin3, 128);  // Stop
        analogWrite(motorPin4, 128);  // Stop
        break;
    }
  }
}
