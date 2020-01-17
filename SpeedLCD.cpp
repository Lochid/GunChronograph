#include "SpeedLCD.h"

SpeedLCD::SpeedLCD(LiquidCrystal *lcd)
{
    _lcd = lcd;
}

SpeedLCD::printSpeed(double speed)
{
    _lcd->setCursor(0, 0);
    _lcd->print("speed");
    _lcd->setCursor(0, 1);
    _lcd->print(speed);
    _lcd->print("m/s");
}
