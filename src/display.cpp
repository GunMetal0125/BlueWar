#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "display.h"

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void initDisplay() {
    Wire.begin(21, 22);  // SDA, SCL

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println("Display failed to start!");
        return;
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("BT Scanner Ready");
    display.display();
}

void showDevice(const char* mac, int rssi, const char* name) {
    display.clearDisplay();
    display.setCursor(0, 0);

    display.println("BT Device Found");
    display.print("MAC: ");
    display.println(mac);

    display.print("RSSI: ");
    display.println(rssi);

    if (name != nullptr) {
        display.print("Name: ");
        display.println(name);
    }

    display.display();
}
