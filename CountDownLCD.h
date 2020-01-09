#include <LiquidCrystal_I2C.h>
#include "CountDown.h"

#ifndef CountDownLCD_h
#define CountDownLCD_h

class CountDownLCD
{
private:
    LiquidCrystal_I2C *_lcd;
    CountDown *_countDown;

public:
    CountDownLCD(LiquidCrystal_I2C *lcd, CountDown *countDown);
    printCountDown();
};

#endif //CountDownLCD.h
