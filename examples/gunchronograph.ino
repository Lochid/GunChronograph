#include <GunChronograph.h>

GunChronograph *gc;
bool photoresistorsSetupped = false;
bool potentiometerSetupped = false;
bool speedChecked = false;
void setup()
{
  Serial.begin(9600);
  gc = new GunChronograph();
  gc->initLCD(13, 12, 11, 10, 9, 8);
  gc->initPhotoresistors(A2, A0, 100);
  gc->initPotentiometer(A4);
  gc->startSetupPhotoresistor();
}
void loop()
{
  int val = analogRead(A0);
  Serial.print("A0: ");
  Serial.println(val);
  val = analogRead(A2);
  Serial.print("A2: ");
  Serial.println(val);
  if (!photoresistorsSetupped)
  {
    photoresistorsSetupped = gc->setupPhotoresistor();
  }
  if (!potentiometerSetupped && photoresistorsSetupped)
  {
    gc->setupPotentiometer();
    potentiometerSetupped = true;
  }
  if (photoresistorsSetupped && potentiometerSetupped && !speedChecked)
  {
    gc->checkPotentiometer();
    speedChecked = gc->checkSpeed();
  }
}
