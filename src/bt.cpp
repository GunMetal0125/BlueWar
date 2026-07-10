#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
#include "display.h"

BLEScan* pBLEScan;

class BTCallback : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice device) {
    const char* mac = device.getAddress().toString().c_str();
    int rssi = device.getRSSI();
    const char* name = device.haveName() ? device.getName().c_str() : nullptr;

    Serial.println("----- Bluetooth Device Found -----");
    Serial.print("MAC: ");
    Serial.println(mac);
    Serial.print("RSSI: ");
    Serial.println(rssi);
    if (name) {
      Serial.print("Name: ");
      Serial.println(name);
    }

    showDevice(mac, rssi, name);
  }
};

void initBluetoothScanner() {
  Serial.println("Initializing Bluetooth...");
  BLEDevice::init("ESP32_BT_Scanner");

  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new BTCallback());
  pBLEScan->setActiveScan(true);
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);

  Serial.println("Bluetooth initialized.");
}

void startBluetoothScan() {
  Serial.println("Starting Bluetooth scan...");
  pBLEScan->start(5, false);
  Serial.println("Scan complete.");
}
