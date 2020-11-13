#include <Wire.h>
#include "SSD1306.h"
#define PIR 14

SSD1306 display(0x3c, 4, 5); //define Instance for  OLED1306 Library

void setup()
{
  pinMode(PIR, INPUT);
  display.init();
  display.flipScreenVertically();
}

void loop()
{
  display.clear();

  getPIR(); //read motion data
}

void getPIR()
{
  if (digitalRead(14) == HIGH) //Read Motion sensor
  {
    draw(true);
  }
  else
  {
    draw(false);
  }

  delay(500);
}

void draw(bool isDetect)
{
  display.clear();

  if (isDetect)
  {    
    display.setFont(ArialMT_Plain_10);
    display.drawString(45, 30, "Motion Detected");    
  }
  else
  {
    display.setFont(ArialMT_Plain_10);
    display.drawString(45, 30, "No Motion");   
  }

  display.display();
}
