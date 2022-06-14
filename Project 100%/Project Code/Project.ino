#define BLYNK_PRINT Serial

#include "CytronMotorDriver.h"
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define BLYNK_PRINT DebugSerial
SoftwareSerial SwSerial(0, 1); // RX, TX
#include <BlynkSimpleSerialBLE.h>
const int trigPin = 13;
int echoPin = 12;
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);
CytronMD motor1(PWM_PWM, 3, 4);   // PWM 1A = Pin 3, PWM 1B = Pin 4.
CytronMD motor2(PWM_PWM, 12, 13); // PWM 2A = Pin 12, PWM 2B = Pin 13.

char auth[] = "ocF_FPUfQhTO1LS5e-5EvOBOxocdTmuF";


void setup()
{
  Serial.begin(9600);

  SerialBLE.begin(38400);
  Blynk.begin(SerialBLE, auth);
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

  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
// FORWARD
 BLYNK_WRITE(V1) {
  int button = param.asInt(); 
  if (button == 1) {
    Serial.println("Moving forward");

    motor1.setSpeed(128);
    motor2.setSpeed(128); 
}
  else {
    motor1.setSpeed(0);
    motor2.setSpeed(0); 
  }
}
// BACKWARD
BLYNK_WRITE(V2) {
  int button = param.asInt(); 
  if (button == 1) {
    Serial.println("Moving backward");

    motor1.setSpeed(-128);
    motor2.setSpeed(-128); 
  }
  else {
    motor1.setSpeed(0);
    motor2.setSpeed(0); 
  }

}
// TURN LEFT
BLYNK_WRITE(V3) {
  int button = param.asInt(); 
  if (button == 1) {
    Serial.println("Moving turn left");


    motor1.setSpeed(-128);
    motor2.setSpeed(128); 
  }
  else {
    motor1.setSpeed(0);
    motor2.setSpeed(0); 
  }
}
// TURN RIGHT
BLYNK_WRITE(V4) {
  int button = param.asInt(); 
  if (button == 1) {
    Serial.println("Moving turn right");

    motor1.setSpeed(128);
    motor2.setSpeed(-128); 
  }
  else {
    motor1.setSpeed(0);
    motor2.setSpeed(0); 
}
void loop()
{
  Blynk.run();
  long duration;
  int cm;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(5);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
cm =  duration * 0.034 / 2;

 if(cm <= 20) 
  {
    tone(8, 300,100);
    oled.clearDisplay();
    oled.setCursor(0, 0);
    oled.setTextSize(2);
    oled.println("Barricade");
    oled.display();
    delay(1000);
    digitalWrite(motor1,Low);
    digitalWrite(motor2,Low);

  }
  else 
  {
    
  }
  
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextSize(1.5);
  oled.setTextColor(WHITE);
  oled.print("distance :");
  oled.print(cm);
  oled.display();
  delay(500);
  Serial.println(cm);
}

