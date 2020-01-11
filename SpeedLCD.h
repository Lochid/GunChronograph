#include <LiquidCrystal_I2C.h>

#ifndef SpeedLCD_h
#define SpeedLCD_h

class SpeedLCD
{
private:
    LiquidCrystal_I2C *_lcd;

public:
    SpeedLCD(LiquidCrystal_I2C *lcd);
    printSpeed(double speed);
};

#endif //SpeedLCD.h
