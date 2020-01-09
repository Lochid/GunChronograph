#include "Photoresistor.h"

void Photoresistor::setMiddleValue()
{
    _middleValue = (double)_fullValue / _iterator->getIteration();
}

Photoresistor::Photoresistor(char port, unsigned int maximalSetupIteration, unsigned int lightPercent)
{
    _iterator = new Iterator(maximalSetupIteration);
    _fullValue = 0.0;
    _middleValue = 0.0;
    _lightPercent = lightPercent;
}

double Photoresistor::getProgress()
{
    return _iterator->getProgress();
}

bool Photoresistor::getCompleteSetupStatus()
{
    return _iterator->getCompleteStatus();
}

double Photoresistor::getMiddleValue()
{
    return _middleValue;
}

void Photoresistor::setValue(double val)
{
    _fullValue += val;
    _iterator->next();
    setMiddleValue();
}

void Photoresistor::nextSetup()
{
    int val = analogRead(_port);
    setValue(val);
}

void Photoresistor::reset()
{
    _iterator->reset();
    _fullValue = 0.0;
    _middleValue = 0.0;
}

bool Photoresistor::checkTurnOff()
{
    int val = analogRead(_port);
    return _middleValue - val > _middleValue / 100 * _lightPercent;
}
