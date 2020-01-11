#include <LiquidCrystal_I2C.h>
#include "Partial.h"

#ifndef PartialLCD_h
#define PartialLCD_h

class PartialLCD
{
private:
    LiquidCrystal_I2C *_lcd;
    Partial *_partial;

public:
    PartialLCD(LiquidCrystal_I2C *lcd);
    printName(char* name);
    printPartial(Partial *partial);
};

#endif //PartialLCD.h
