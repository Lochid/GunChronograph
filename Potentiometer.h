#include <Arduino.h>
#include "Partial.h"

#ifndef Potentiometer_h
#define Potentiometer_h

class Potentiometer : Partial
{
private:
    char _port;

public:
    Potentiometer(char port)
    {
        _port = port;
    }

    double getPartValue()
    {
        int val = analogRead(_port);
        return (double)val / 1023;
    }
};

#endif //Potentiometer.h
