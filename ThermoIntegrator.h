#ifndef THERMOINTEGRATOR_H
#define THERMOINTEGRATOR_H


#include "LegacyThermostat.h"
#include "Thermostat.h"
class ThermostatState;

class ThermoIntegrator : public Thermostat // ADAPTER
{
private:
   LegacyThermostat* legacyThermostat;
   ThermostatState* currentState;
public:
   ThermoIntegrator(LegacyThermostat* legacy);
   ~ThermoIntegrator(); // delete legacy
   string getType();
   void display();
   void setStatus(ThermostatState* state);
   void update(); // when there is a temperature change, it will notify the thermostat to work
   void setTemperature(double temperature);
   double getTemperature();
   string getStatus();
   void cool();
   void heat();
   void idle();
};

#endif