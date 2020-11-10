#include <Wire.h>
#include "SSD1306.h"
#include "DHT.h"
#define DHTPIN D3     //define input pin for DHT Data
#define DHTTYPE DHT11 //Define DHT Sensor model

DHT dht(DHTPIN, DHTTYPE);    //define Instance for DHT.h Library
SSD1306 display(0x3c, 4, 5); //define Instance for  OLED1306 Library

float hum = 0.0f;
float temp = 0.0f;

void setup()
{
  display.init();
  display.flipScreenVertically();

  dht.begin();
}

void loop()
{
  display.clear();

  getDHT();  //read DHT 22 Sensor data
  drawDHT(); //show DHT sensor data on OLED
  
  display.display(); //Display all in OLED
}

void getDHT()
{
  float localTemp = dht.readTemperature();   // Read temperature as Celsius (the default)
  float localHum = dht.readHumidity();  // Read humidity

  if (isnan(localTemp) || isnan(localHum))
  {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  } else {
    temp = localTemp;
    hum = localHum;
  }
}

void drawDHT()
{
  int x = 0;
  int y = 0;

  display.setFont(ArialMT_Plain_10);
  String humdht22 = String(hum);
  display.drawString(46 + x, 30 + y, humdht22 + "%");

  display.setFont(ArialMT_Plain_10);
  String tempdht22 = String(temp);
  display.drawString(46 + x, 48 + y, tempdht22 + "°C");
}
