#include "CountDownLCD.h"

CountDownLCD::CountDownLCD(LiquidCrystal_I2C *lcd, CountDown *countDown)
{
    _lcd = lcd;
    _countDown = countDown;
}

CountDownLCD::printCountDown()
{
    _lcd->setCursor(0, 0);
    double progress = _countDown->getProgress();
    _lcd->print((int)progress);
    _lcd->print("%");
}
