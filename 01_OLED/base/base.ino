#include <Wire.h>
#include <SSD1306.h>
#include "SSD1306.h"

SSD1306 display(0x3c, 4, 5);

void setup()
{
    display.init();
}

void loop()
{
    display.clear();

    //TEXT_ALIGN_LEFT , TEXT_ALIGN_CENTER,  TEXT_ALIGN_RIGHT , TEXT_ALIGN_CENTER_BOTH
    display.setTextAlignment(TEXT_ALIGN_LEFT);

    //ArialMT_Plain_10 , ArialMT_Plain_16 , ArialMT_Plain_24 or create with this tool http://oleddisplay.squix.ch
    //display.setFont(Unkempt_16);

    display.drawString(30, 15, "abcdefg");
    display.drawString(30, 28, "mhkarami 97");
    display.flipScreenVertically();
    display.display();

    delay(2000);
    display.clear();

    display.setTextAlignment(TEXT_ALIGN_RIGHT);
    //display.setFont(ArialMT_Plain_10);
    display.drawString(-25, -25, "hello");
    display.drawString(-30,- 30, "how are you");
    display.flipScreenVertically();
    display.display();

    delay(1000);
}
