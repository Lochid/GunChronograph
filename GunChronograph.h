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
    initLCD(uint8_t rs, uint8_t enable, uint8_t d4, uint8_t d5, uint8_t d6, uint8_t d7);
    initPhotoresistors(uint8_t firstPort, uint8_t secondPort, unsigned int maximalSetupIteration);
    initPotentiometer(uint8_t port);
    startSetupPhotoresistor();
    bool setupPhotoresistor();
    bool setupPotentiometer();
    void checkPotentiometer();
    bool checkSpeed();
    double getPartValue();
    bool getCompleteSetupStatus();
};

#endif //GunChronograph.h
