#include <Arduino.h>
#include "bt.h"
#include "display.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  initDisplay();
  initBluetoothScanner();
}

void loop() {
  startBluetoothScan();
  delay(2000);
}
#include <Arduino.h>
#include "bt.h"
#include "display.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  initDisplay();
  initBluetoothScanner();
}

void loop() {
  startBluetoothScan();
  delay(2000);
}
