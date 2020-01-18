#include "GunChronograph.h"

GunChronograph::initLCD(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7)
{
    _lcd = new LiquidCrystal(rs, enable, d4, d5, d6, d7);
    _lcd->begin(16, 2);
    _partialLCD = new PartialLCD(_lcd);
    _speedLCD = new SpeedLCD(_lcd);
}

GunChronograph::initPhotoresistors(uint8_t firstPort, uint8_t secondPort, unsigned int maximalSetupIteration)
{
    _firstPhotoresistor = new Photoresistor(firstPort, maximalSetupIteration);
    _secondPhotoresistor = new Photoresistor(secondPort, maximalSetupIteration);
}

GunChronograph::initPotentiometer(uint8_t port)
{
    _potentiometer = new Potentiometer(port);
}

GunChronograph::startSetupPhotoresistor()
{
    _partialLCD->printName("setup");
}

bool GunChronograph::setupPhotoresistor()
{
    _firstPhotoresistor->nextSetup();
    _secondPhotoresistor->nextSetup();

    _partialLCD->printPartial((Partial *)this);

    return this->getCompleteSetupStatus();
}

bool GunChronograph::setupPotentiometer()
{
    _partialLCD->printName("sensitivity");
}

void GunChronograph::checkPotentiometer()
{
    _partialLCD->printPartial((Partial *)this);
}

bool GunChronograph::checkSpeed()
{
    if (_startTime == 0 && _firstPhotoresistor->checkTurnOff(_potentiometer->getPartValue()))
    {
        _startTime = micros();
        return false;
    }
    if (_startTime != 0 && _secondPhotoresistor->checkTurnOff(_potentiometer->getPartValue()))
    {
        _endTime = micros();
        double speed = tubeLength / (_endTime - _startTime);
        _speedLCD->printSpeed(speed);
        _startTime = 0;
        _endTime = 0;
        return true;
    }
    return false;
}

double GunChronograph::getPartValue()
{
    if (this->getCompleteSetupStatus())
    {
        return _potentiometer->getPartValue();
    }

    return (_firstPhotoresistor->getPartValue() + _secondPhotoresistor->getPartValue()) / 2;
}

bool GunChronograph::getCompleteSetupStatus()
{
    return _firstPhotoresistor->getCompleteSetupStatus() && _secondPhotoresistor->getCompleteSetupStatus();
}