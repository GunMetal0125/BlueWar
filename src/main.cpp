#include <Arduino.h>
#include "bt.h"

void setup() {
  Serial.begin(115200);
  delay(1000);

  initBluetoothScanner();
}

void loop() {
  startBluetoothScan();
  delay(2000);  // wait before scanning again
}
