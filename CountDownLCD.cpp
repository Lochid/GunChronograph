#include "CountDownLCD.h"

CountDownLCD::CountDownLCD(LiquidCrystal_I2C *lcd, Partial *countDown)
{
    _lcd = lcd;
    _countDown = countDown;
}

CountDownLCD::printCountDown()
{
    _lcd->setCursor(0, 0);
    double progress = _countDown->getPartValue();
    _lcd->print((int)progress);
    _lcd->print("%");
}
