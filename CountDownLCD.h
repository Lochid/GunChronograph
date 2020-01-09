#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "CountDown.h"

#ifndef CountDownLCD_h
#define CountDownLCD_h

class CountDownLCD : CountDown
{
private:
    LiquidCrystal_I2C _lcd = LiquidCrystal_I2C(0x27, 16, 2);
    CountDown _countDown;

public:
    CountDownLCD(LiquidCrystal_I2C lcd, CountDown countDown)
    {
        _lcd = lcd;
        _countDown = countDown;
    }

    printCountDown()
    {
        _lcd.setCursor(0, 0);
        double progress = _countDown.getProgress();
        _lcd.print((int)progress);
        _lcd.print("%");
    }
};

#endif //CountDownLCD.h
