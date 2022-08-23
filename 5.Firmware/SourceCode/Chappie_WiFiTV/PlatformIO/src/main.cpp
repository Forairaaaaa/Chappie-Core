/*----------------------------------------------------------------------------/
  Chappie - An Open Source TV Player
/----------------------------------------------------------------------------*/
#include <Arduino.h>
#include <esp_wifi.h>
#include "src/LGFX_ChappieCore.hpp"
#include "src/TCPReceiver.h"

static LGFX_ChappieCore lcd;
static TCPReceiver recv;

const char* SSID = "";
const char* WiFiPassword = "";

void connectWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, WiFiPassword);
    Serial.print("Connecting to "); Serial.println(SSID);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }
    Serial.print(F("Connected. My IP address is: "));
    Serial.println(WiFi.localIP());
}

void setup(void) {
    Serial.begin(115200);
    Serial.flush();

    lcd.begin();
    //lcd.setColorDepth(24);
    lcd.setRotation(0);
    if (lcd.width() < lcd.height())
        lcd.setRotation(1);

    lcd.setFont(&fonts::Font2);

    Serial.println("WiFi begin.");
    lcd.println("WiFi begin.");
    connectWiFi();

    Serial.println(String("IP:") + WiFi.localIP().toString());
    lcd.println(WiFi.localIP().toString());

    recv.setup( &lcd );
}

void loop(void) {
    recv.loop();
}
