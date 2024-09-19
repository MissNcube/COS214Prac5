#ifndef THERMOSTATSTATE_H
#define THERMOSTATSTATE_H

class Thermostat;
#include <string>
using namespace std;

class ThermostatState 
{
private:
   /* data */
public:
 virtual ~ThermostatState() {}
   
   // Virtual methods that the state will implement
   virtual void cool(Thermostat* thermostat) = 0;
   virtual void heat(Thermostat* thermostat) = 0;
   virtual void idle(Thermostat* thermostat) = 0;
   virtual string toString() = 0;
};

#endif