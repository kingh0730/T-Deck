#include "_loop.h"

void _loop(TFT_eSPI &tft)
{
    tft.setTextColor(random(0xFFFF));
    tft.fillScreen(TFT_BLACK);
    tft.drawString("Hello loop", random(5, 320), random(5, 240));
    delay(5000);
}
