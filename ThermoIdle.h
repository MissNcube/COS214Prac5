#ifndef THERMOIDLE_H
#define THERMOIDLE_H

#include "ThermostatState.h"


class ThermoIdle :public ThermostatState
{
private:
   /* data */
public:
   ThermoIdle(/* args */);
   ~ThermoIdle();
   void cool(Thermostat* thermostat);
   void heat(Thermostat* thermostat);
   void idle(Thermostat* thermostat);

};



#endif