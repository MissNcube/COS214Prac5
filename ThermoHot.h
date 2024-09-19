#ifndef THERMOHOT_H
#define THERMOHOT_H

#include "ThermostatState.h"
#include <iostream>
#include <string>
using namespace std;
class Thermostat;


class ThermoHot :public ThermostatState
{
private:
   string name;
public:
   ThermoHot();
   void cool(Thermostat* thermostat);
   void heat(Thermostat* thermostat);
   void idle(Thermostat* thermostat);
   string toString();

};



#endif