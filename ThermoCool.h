#ifndef THERMOCOOL_H
#define THERMOCOOL_H

#include "ThermostatState.h"
class ThermoCool : public ThermostatState
{
private:
   /* data */
public:
   ThermoCool(/* args */);
   ~ThermoCool();
   void cool(Thermostat* thermostat);
   void heat(Thermostat* thermostat);
   void idle(Thermostat* thermostat);

};


#endif