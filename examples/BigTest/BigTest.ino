#include <AccelStepper.h>
#include "ET4000v2_pins.h"


/* connect an 0.96inch I2C OLED and install Adafruit_SSD1306
 * J1/12  <-> VDD
 * J1/11  <-> GND
 * J1/4   <-> SCL
 * J1/2   <-> SDA
 */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET      -1   // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS  0x3C // 0x3C for 128x32
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



// Interface-Typ 1 bedeutet: Ansteuerung über Step- und Dir-Pins
AccelStepper xAxis(AccelStepper::DRIVER, XSTEP, XDIR);
AccelStepper yAxis(AccelStepper::DRIVER, YSTEP, YDIR);
AccelStepper zAxis(AccelStepper::DRIVER, ZSTEP, ZDIR);
AccelStepper eAxis(AccelStepper::DRIVER, ESTEP, EDIR);


void setup() {
  Serial.begin(115200);
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  oled.clearDisplay();
  oled.setTextSize(2);              // Normal 1:1 pixel scale
  oled.setTextColor(SSD1306_WHITE); // Draw white text
  oled.cp437(true);                 // Use full 256 char 'Code Page 437' font

  pinMode(XYE_ENABLE, OUTPUT);
  pinMode(ZENABLE   , OUTPUT);
  digitalWrite(XYE_ENABLE, HIGH);
  digitalWrite(ZENABLE   , HIGH); 

  // axis config
  xAxis.setMaxSpeed(10000);     // steps per second
  yAxis.setMaxSpeed(10000);
  zAxis.setMaxSpeed(10000);
  eAxis.setMaxSpeed(10000);
  xAxis.setAcceleration(5000);  // acceleration/decceleration
  yAxis.setAcceleration(5000);
  zAxis.setAcceleration(5000);
  eAxis.setAcceleration(5000);

  // cooling fan + LED
  pinMode(FAN   , OUTPUT);
  analogWrite(FAN, 128);

  // temp sensors
  pinMode(TBED   , INPUT);
  pinMode(THOTEND, INPUT);
  
  pinMode(BEDHEATER, OUTPUT);
  pinMode(HOTEND   , OUTPUT);
  digitalWrite(BEDHEATER, HIGH);
  digitalWrite(HOTEND   , HIGH);


  
}

int st = 0;
int on = 0;
int spd;
unsigned long lastMillis;

void loop() {
  switch(st) {
     case 0:
        if (xAxis.distanceToGo() == 0) {
           digitalWrite(XYE_ENABLE, LOW);
           digitalWrite(ZENABLE, HIGH);
           Serial.println("toggling X");
           delay(250);
           xAxis.moveTo(-xAxis.currentPosition() + 20000); 
           }
        xAxis.run();
        break;
     case 1:
        if (yAxis.distanceToGo() == 0) {
           digitalWrite(XYE_ENABLE, LOW);
           digitalWrite(ZENABLE, HIGH);
           Serial.println("toggling Y");
           delay(250);
           yAxis.moveTo(-yAxis.currentPosition() + 20000); 
           }
        yAxis.run();
        break;
     case 2:
        if (zAxis.distanceToGo() == 0) {
           digitalWrite(XYE_ENABLE, HIGH);
           digitalWrite(ZENABLE, LOW);
           Serial.println("toggling Z");
           delay(250);
           zAxis.moveTo(-zAxis.currentPosition() + 20000); 
           }
        zAxis.run();
        break;
     case 3:
        if (eAxis.distanceToGo() == 0) {
           digitalWrite(XYE_ENABLE, LOW);
           digitalWrite(ZENABLE, HIGH);
           Serial.println("toggling E");
           delay(250);
           eAxis.moveTo(-eAxis.currentPosition() + 20000); 
           }
          eAxis.run();
        break;        
     case 4: {
          spd = random(255);
          Serial.print("setting FAN to "); Serial.println(spd);
          analogWrite(FAN, spd);
          delay(500);
          }
        break;
     case 5:
        on = !on;
        Serial.print("setting BEDHEATER to "); Serial.println(on);
        digitalWrite(BEDHEATER, !on); // low side switch.
        delay(500);
        break;
     case 6:
        on = on?0:1;
        Serial.print("setting HOTEND to "); Serial.println(on);
        digitalWrite(HOTEND, !on); // low side switch.
        delay(500);
        break;
     case 7:
        on = on?0:1;
        Serial.print("reading TBED: "); Serial.println(analogRead(TBED));
        delay(200);
        break;
     case 8:
        on = !on;
        Serial.print("reading THOTEND: "); Serial.println(analogRead(THOTEND));
        delay(200);
        break;
  }

  if ((millis() - lastMillis) > 5000) {
     st++;
     if (st > 8) st = 0;
     lastMillis = millis();
     oled.clearDisplay();
     oled.setCursor(0, 0);             // Start at top-left corner
     oled.println(st);
     oled.display();
     }


}
