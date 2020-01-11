#include <Arduino.h>
#include "Partial.h"

#ifndef Potentiometer_h
#define Potentiometer_h

class Potentiometer : Partial
{
private:
    char _port;

public:
    Potentiometer(char port);
    double getPartValue();
};

#endif //Potentiometer.h
