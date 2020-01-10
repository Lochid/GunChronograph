#include "PartialLCD.h"

PartialLCD::PartialLCD(LiquidCrystal_I2C *lcd, Partial *partial)
{
    _lcd = lcd;
    _partial = partial;
}

PartialLCD::printPartial()
{
    _lcd->setCursor(0, 0);
    double progress = _partial->getPartValue();
    _lcd->print((int)progress);
    _lcd->print("%");
}
