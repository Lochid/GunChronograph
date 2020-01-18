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

bool Potentiometer::wasUpdated()
{
    if (_oldPotentional - _newPotentional < 0.01 && _oldPotentional - _newPotentional > -0.01)
    {
        _newPotentional = analogRead(_port);
    }

    return _oldPotentional - _newPotentional > 0.01 || _oldPotentional - _newPotentional < -0.01;
}

Potentiometer::updatePotentional()
{
    _oldPotentional = _newPotentional;
}
