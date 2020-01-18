#include <LiquidCrystal.h>
#include "Partial.h"

#ifndef PartialLCD_h
#define PartialLCD_h

class PartialLCD
{
private:
    LiquidCrystal *_lcd;
    Partial *_partial;

public:
    PartialLCD(LiquidCrystal *lcd);
    printName(char* name);
    printPartial(Partial *partial);
};

#endif //PartialLCD.h
