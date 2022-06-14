#define BLYNK_PRINT Serial

#include "CytronMotorDriver.h"
#include <SoftwareSerial.h>
#define BLYNK_PRINT DebugSerial
SoftwareSerial SwSerial(0, 1); // RX, TX
#include <BlynkSimpleSerialBLE.h>
CytronMD motor1(PWM_PWM, 3, 4);   // PWM 1A = Pin 3, PWM 1B = Pin 4.
CytronMD motor2(PWM_PWM, 12, 13); // PWM 2A = Pin 12, PWM 2B = Pin 13.

char auth[] = "ocF_FPUfQhTO1LS5e-5EvOBOxocdTmuF";


void setup()
{
  Serial.begin(9600);

  SerialBLE.begin(38400);
  Blynk.begin(SerialBLE, auth);

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
}

