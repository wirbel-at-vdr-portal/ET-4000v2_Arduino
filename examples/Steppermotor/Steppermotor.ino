#include <AccelStepper.h>
#include "ET4000v2_pins.h"

// Interface-Typ 1 means via step and dir pins

//AccelStepper xAxis(AccelStepper::DRIVER, XSTEP, XDIR);
//AccelStepper yAxis(AccelStepper::DRIVER, YSTEP, YDIR);
AccelStepper eAxis(AccelStepper::DRIVER, ESTEP, EDIR);

void setup() {
  Serial.begin(115200);
  // NOTE: the enable pin is low active
  pinMode(XYE_ENABLE, OUTPUT);
  digitalWrite(XYE_ENABLE, LOW);

  

  // setup maximum speed and acceleration
 // xAxis.setMaxSpeed(10000);     // steps per second
  //xAxis.setAcceleration(5000);  // acceleration
  //yAxis.setMaxSpeed(10000);     // steps per second
  //yAxis.setAcceleration(5000);  // acceleration
  eAxis.setMaxSpeed(10000);     // steps per second
  eAxis.setAcceleration(5000);  // acceleration


}

void loop() { 
  // as soon as the motor reached his goal value, move back to start pos

  /*if (xAxis.distanceToGo() == 0) {
       delay(500);
       // 800 steps is for 1/16 micro stepping and
       // 20-teath-pulley one revolution or 40mm distance
       xAxis.moveTo(-xAxis.currentPosition() + 16000); 
       }
   */
  /*if (yAxis.distanceToGo() == 0) {
       delay(500);
       // 800 steps is for 1/16 micro stepping and
       // 20-teath-pulley one revolution or 40mm distance
       yAxis.moveTo(-xAxis.currentPosition() + 16000); 
       }
   */
  if (eAxis.distanceToGo() == 0) {
     delay(500);
       // 800 steps is for 1/16 micro stepping and
       // 20-teath-pulley one revolution or 40mm distance
     eAxis.moveTo(-eAxis.currentPosition() + 16000); 
     }

  // this call need to be called regularly (often)
  //xAxis.run();
  //yAxis.run();  
  eAxis.run();
}