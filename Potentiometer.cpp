#include "Potentiometer.h"

Potentiometer::Potentiometer(char port)
{
    _port = port;
}

double Potentiometer::getPartValue()
{
    int val = analogRead(_port);
    return (double)val / 1023;
}
