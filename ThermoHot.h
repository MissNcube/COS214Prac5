#ifndef THERMOHOT_H
#define THERMOHOT_H

#include "ThermostatState.h"

class ThermoHot :public ThermostatState
{
private:
   /* data */
public:
   ThermoHot(/* args */);
   ~ThermoHot();
      void cool(Thermostat* thermostat);
   void heat(Thermostat* thermostat);
   void idle(Thermostat* thermostat);

};



#endif