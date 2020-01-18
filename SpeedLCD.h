#include <LiquidCrystal.h>

#ifndef SpeedLCD_h
#define SpeedLCD_h

class SpeedLCD
{
private:
    LiquidCrystal *_lcd;

public:
    SpeedLCD(LiquidCrystal *lcd);
    printSpeed(double speed);
};

#endif //SpeedLCD.h
