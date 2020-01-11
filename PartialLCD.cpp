#include "PartialLCD.h"

PartialLCD::PartialLCD(LiquidCrystal_I2C *lcd)
{
    _lcd = lcd;
}

PartialLCD::printPartial(Partial *partial)
{
    _lcd->setCursor(0, 1);
    double progress = partial->getPartValue();
    _lcd->print((int)progress);
    _lcd->print("%");
}

PartialLCD::printName(char* name)
{
    _lcd->setCursor(0, 0);
    _lcd->print(name);
}
