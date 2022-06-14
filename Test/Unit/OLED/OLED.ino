#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

void setup() {
  pinMode(2, INPUT_PULLUP);

  oled.begin(0x3C); // Address 0x3C for 128x32

  oled.clearDisplay();

  oled.setCursor(0, 0);

  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(3);
  oled.print(" Open");

  oled.display();

  delay(2000);
}

void loop() {
  oled.clearDisplay();
  oled.setCursor(0, 0);
    
  if (!digitalRead(2)) {
    oled.setTextSize(1);
    oled.println("Don't touch me");
  }
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(2);
  oled.print("distance : x cm");
  oled.display();
  delay(10);
}