#include "Iterator.h"

#ifndef Photoresistor_h
#define Photoresistor_h

class Photoresistor
{
private:
    Iterator _iterator = Iterator(0);
    unsigned long _fullValue;
    double _middleValue;
    uint8_t _port;
    uint8_t _lightPercent;

    void setMiddleValue();

public:
    Photoresistor(uint8_t port, unsigned int maximalSetupIteration, unsigned int lightPercent);
    double getSetupProgress();
    bool getCompleteSetupStatus();
    double getMiddleValue();
    void setValue(double val);
    void nextSetup();
    void reset();
    bool checkTurnOff();
};

void Photoresistor::setMiddleValue()
{
    _middleValue = (double)_fullValue / _iterator.getIteration();
}

Photoresistor::Photoresistor(uint8_t port, unsigned int maximalSetupIteration, unsigned int lightPercent)
{
    _iterator = Iterator(maximalSetupIteration);
    _fullValue = 0.0;
    _middleValue = 0.0;
    _lightPercent = lightPercent;
}

double Photoresistor::getSetupProgress()
{
    return _iterator.getProgress();
}

bool Photoresistor::getCompleteSetupStatus()
{
    return _iterator.getCompleteStatus();
}

double Photoresistor::getMiddleValue()
{
    return _middleValue;
}

void Photoresistor::setValue(double val)
{
    _fullValue += val;
    _iterator.next();
    setMiddleValue();
}

void Photoresistor::nextSetup()
{
    int val = analogRead(_port);
    setValue(val);
}

void Photoresistor::reset()
{
    _iterator.reset();
    _fullValue = 0.0;
    _middleValue = 0.0;
}

bool Photoresistor::checkTurnOff()
{
    int val = analogRead(_port);
    return _middleValue - val > _middleValue / 100 * _lightPercent;
}

#endif //Photoresistor.h
