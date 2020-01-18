#include <Arduino.h>
#include "Partial.h"
#include "Iterator.h"

#ifndef Photoresistor_h
#define Photoresistor_h

class Photoresistor: Partial
{
private:
    Iterator* _iterator;
    unsigned long _fullValue;
    double _middleValue;
    char _port;

    void setMiddleValue();

public:
    Photoresistor(char port, unsigned int maximalSetupIteration);
    double getPartValue();
    bool getCompleteSetupStatus();
    double getMiddleValue();
    void setValue(double val);
    void nextSetup();
    void reset();
    bool checkTurnOff(double lightPercent);
};

#endif //Photoresistor.h
