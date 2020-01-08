#include <Arduino.h>
#include "Iterator.h"

#ifndef Photoresistor_h
#define Photoresistor_h

class Photoresistor
{
private:
    Iterator _iterator = Iterator(0);
    unsigned long _fullValue;
    double _middleValue;
    char _port;
    char _lightPercent;

    void setMiddleValue();

public:
    Photoresistor(char port, unsigned int maximalSetupIteration, unsigned int lightPercent);
    double getSetupProgress();
    bool getCompleteSetupStatus();
    double getMiddleValue();
    void setValue(double val);
    void nextSetup();
    void reset();
    bool checkTurnOff();
};

#endif //Photoresistor.h
