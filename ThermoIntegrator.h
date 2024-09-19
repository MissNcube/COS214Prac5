#ifndef THERMOINTEGRATOR_H
#define THERMOINTEGRATOR_H


#include "LegacyThermostat.h"
#include "SmartDevice.h"
class ThermostatState;

class ThermoIntegrator : public SmartDevice // ADAPTER
{
private:
   LegacyThermostat* legacyThermostat;
   ThermostatState* currentState;
public:
   ThermoIntegrator(LegacyThermostat* legacy);
   ~ThermoIntegrator(); // delete legacy
   string getType();
   void setStatus(ThermostatState* state);
   void update(); // when there is a temperature change, it will notify the thermostat to work
   void setTemperature(double temperature);
   double getTemperature();
   void cool();
   void heat();
   void idle();
};

#endif