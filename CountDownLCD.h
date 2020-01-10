#include <LiquidCrystal_I2C.h>
#include "Partial.h"

#ifndef CountDownLCD_h
#define CountDownLCD_h

class CountDownLCD
{
private:
    LiquidCrystal_I2C *_lcd;
    Partial *_countDown;

public:
    CountDownLCD(LiquidCrystal_I2C *lcd, Partial *countDown);
    printCountDown();
};

#endif //CountDownLCD.h
