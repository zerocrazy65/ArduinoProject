#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "CytronMotorDriver.h"
const int trigPin = 13;
int echoPin = 12;
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);
CytronMD motor1(PWM_PWM, 3, 4);   // PWM 1A = Pin 3, PWM 1B = Pin 4.
CytronMD motor2(PWM_PWM, 10, 11); // PWM 2A = Pin 10, PWM 2B = Pin 11.

void setup() {
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(8,OUTPUT);
 oled.begin(0x3C); 
 oled.clearDisplay();
 oled.setCursor(0, 0);
 oled.setTextColor(SSD1306_WHITE);
 oled.setTextSize(3);
 oled.print(" Open");
 oled.display();

 delay(2000);
}

void loop()
{
long duration;
int cm;
for(int i = 0 ; i<= 100 ; i++){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
cm =  duration * 0.034 / 2;
Serial.print(cm);
}
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.print("distance :");
  oled.print(cm);
  oled.display();

     if(cm <= 20) 
     {
       motor1.setSpeed(0);     
       motor2.setSpeed(0);     
       tone(8, 500,150);
        oled.clearDisplay();
        oled.setCursor(0, 0);
        oled.setTextSize(2);
        oled.println("Barricade");
        oled.display();    
        delay(1000);

     }
     else 
     {
         motor1.setSpeed(255);     
         motor2.setSpeed(255); 
     }
    
}
     




