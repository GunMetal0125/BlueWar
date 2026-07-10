#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

BLEScan* pBLEScan;

class BTCallback : public BLEAdvertisedDeviceCallbacks {
  void onResult(BLEAdvertisedDevice device) {
    Serial.println("----- Bluetooth Device Found -----");
    Serial.print("MAC: ");
    Serial.println(device.getAddress().toString().c_str());

    Serial.print("RSSI: ");
    Serial.println(device.getRSSI());

    if (device.haveName()) {
      Serial.print("Name: ");
      Serial.println(device.getName().c_str());
    }

    Serial.println("----------------------------------");
  }
};

void initBluetoothScanner() {
  Serial.println("Initializing Bluetooth...");
  BLEDevice::init("ESP32_BT_Scanner");

  pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new BTCallback());
  pBLEScan->setActiveScan(true);  // active scan = more data
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);

  Serial.println("Bluetooth initialized.");
}

void startBluetoothScan() {
  Serial.println("Starting Bluetooth scan...");
  pBLEScan->start(5, false);  // scan for 5 seconds
  Serial.println("Scan complete.");
}
