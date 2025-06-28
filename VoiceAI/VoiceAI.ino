#include <ArduinoBLE.h>

/*
  VoiceAI
  - BLE service to receive commands from AI engine
  - Controls relay for home automation
*/

BLEService controlService("12345678-1234-5678-1234-56789abcdef0");
BLECharacteristic commandChar("12345678-1234-5678-1234-56789abcdef1", BLEWrite, 20);

const int RELAY_PIN = 7;

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  BLE.begin();
  controlService.addCharacteristic(commandChar);
  BLE.addService(controlService);
  BLE.advertise();

  Serial.println("VoiceAI BLE service started");
}

void loop() {
  BLEDevice central = BLE.central();
  if (central) {
    while (central.connected()) {
      if (commandChar.written()) {
        String cmd = commandChar.value();
        Serial.print("Command: "); Serial.println(cmd);
        if (cmd == "ON") digitalWrite(RELAY_PIN, HIGH);
        else if (cmd == "OFF") digitalWrite(RELAY_PIN, LOW);
      }
    }
  }
}