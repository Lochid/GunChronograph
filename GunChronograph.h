#include <Arduino.h>
#include <LiquidCrystal.h>
#include "Iterator.h"
#include "Partial.h"
#include "Photoresistor.h"
#include "Potentiometer.h"
#include "PartialLCD.h"
#include "SpeedLCD.h"

#ifndef GunChronograph_h
#define GunChronograph_h
#define tubeLength 160000.0

class GunChronograph : Partial
{
private:
    Photoresistor *_firstPhotoresistor;
    Photoresistor *_secondPhotoresistor;
    Potentiometer *_potentiometer;
    LiquidCrystal *_lcd;
    PartialLCD *_partialLCD;
    SpeedLCD *_speedLCD;
    unsigned long _startTime = 0;
    unsigned long _endTime = 0;

public:
    initLCD(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
    {
        _lcd = new LiquidCrystal(rs, enable, d4, d5, d6, d7);
        _partialLCD = new PartialLCD(_lcd);
        _speedLCD = new SpeedLCD(_lcd);
    }

    initPhotoresistors(uint8_t firstPort, uint8_t secondPort, unsigned int maximalSetupIteration)
    {
        _firstPhotoresistor = new Photoresistor(firstPort, maximalSetupIteration);
        _secondPhotoresistor = new Photoresistor(secondPort, maximalSetupIteration);
    }

    initPotentiometer(char port)
    {
        _potentiometer = new Potentiometer(port);
    }

    startSetupPhotoresistor()
    {
        _partialLCD->printName("setup");
    }

    bool setupPhotoresistor()
    {
        _firstPhotoresistor->nextSetup();
        _secondPhotoresistor->nextSetup();

        _partialLCD->printPartial((Partial *)this);

        return this->getCompleteSetupStatus();
    }

    bool setupPotentiometer()
    {
        _partialLCD->printName("sensitivity");
    }

    double getPartValue()
    {
        if (this->getCompleteSetupStatus())
        {
            return _potentiometer->getPartValue();
        }

        return (_firstPhotoresistor->getPartValue() + _secondPhotoresistor->getPartValue()) / 2;
    }

    bool getCompleteSetupStatus()
    {
        return _firstPhotoresistor->getCompleteSetupStatus() && _secondPhotoresistor->getCompleteSetupStatus();
    }

    void checkSpeed()
    {
        if (_startTime == 0 && _firstPhotoresistor->checkTurnOff(_potentiometer->getPartValue()))
        {
            _startTime = micros();
            return;
        }

        if (_startTime != 0 && _secondPhotoresistor->checkTurnOff(_potentiometer->getPartValue()))
        {
            _endTime = micros();
            double speed = tubeLength / (_endTime - _startTime);
            _speedLCD->printSpeed(speed);
            _startTime = 0;
            _endTime = 0;
        }
    }
};

#endif //GunChronograph.h
