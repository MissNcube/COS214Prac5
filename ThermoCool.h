#ifndef THERMOCOOL_H
#define THERMOCOOL_H

#include "ThermostatState.h"
#include <iostream>
#include <string>
using namespace std;
class Thermostat;

class ThermoCool : public ThermostatState
{
private:
   string name;
public:
   ThermoCool();
   void cool(Thermostat* thermostat);
   void heat(Thermostat* thermostat);
   void idle(Thermostat* thermostat);
   string toString();

};


#endif