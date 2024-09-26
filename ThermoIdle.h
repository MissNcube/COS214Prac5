#ifndef THERMOIDLE_H
#define THERMOIDLE_H

#include "ThermostatState.h"
#include <iostream>
#include <string>
using namespace std;
class Thermostat;

class ThermoIdle :public ThermostatState
{
private:
   string name;
public:
   ThermoIdle();
   void cool(Thermostat* thermostat);
   void heat(Thermostat* thermostat);
   void idle(Thermostat* thermostat);
   string toString();
};



#endif