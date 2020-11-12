#include <Wire.h>
#include "SSD1306.h"

SSD1306 display(0x3c, 4, 5); //define Instance for  OLED1306 Library

float valGas = 0;
float analogVolts = 0;

void setup()
{
  display.init();
  display.flipScreenVertically();
}

void loop()
{
  display.clear();

  getMQ();   //read MQ5 data
  drawDHT(); //show data on OLED

  display.display(); //Display all in OLED
}

void getMQ()
{
  for (int i = 0; i < 10; i++)
  {
    valGas += analogRead(A0);

    delay(50);
  }

  valGas = valGas / 10;
  analogVolts = valGas/1024*5.0;;
}

void drawDHT()
{
  String gas = String(valGas);
  String gasVolt = String(analogVolts);
  display.setFont(ArialMT_Plain_10);
  display.drawString(45, 30, gas + "G");
  display.drawString(45, 46, gasVolt + "V");
}
