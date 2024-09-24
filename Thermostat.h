#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class ThermostatState;
class Thermostat : public SmartDevice
{
private:
   ThermostatState *state;
   double temperature;
   string type;

public:
   Thermostat(); // initial state is idle
   ~Thermostat();
   string getStatus();
   virtual string getType();
   virtual void setStatus(ThermostatState *state);
   virtual void display();
   virtual void update(); // when there is a temperature change, it will notify the thermostat to work
   virtual void setTemperature(double temperature);
   virtual double getTemperature();
   virtual void cool();
   virtual void heat();
   virtual void idle();
   // be able to change state based on temperature
};

#endif