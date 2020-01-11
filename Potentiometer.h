#include <Arduino.h>
#include "Partial.h"

#ifndef Potentiometer_h
#define Potentiometer_h

class Potentiometer : Partial
{
private:
    char _port;
    unsigned short _oldPotentional = 0;
    unsigned short _newPotentional = 0;

public:
    Potentiometer(char port);
    double getPartValue();
    bool wasUpdated();
    updatePotentional();
};

#endif //Potentiometer.h
