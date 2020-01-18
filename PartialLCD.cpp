#include "PartialLCD.h"

PartialLCD::PartialLCD(LiquidCrystal *lcd)
{
    _lcd = lcd;
}

PartialLCD::printPartial(Partial *partial)
{
    _lcd->setCursor(0, 1);
    double progress = partial->getPartValue();
    _lcd->print(progress * 100);
    _lcd->print("%     ");
}

PartialLCD::printName(char *name)
{
    _lcd->setCursor(0, 0);
    _lcd->print(name);
}
