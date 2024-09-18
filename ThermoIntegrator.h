#ifndef THERMOINTEGRATOR_H
#define THERMOINTEGRATOR_H


#include "LegacyThermostat.h"
#include "SmartDevice.h"

class ThermoIntegrator : public LegacyThermostat, public SmartDevice // ADAPTER
{
private:
   /* data */
public:
   ThermoIntegrator(/* args */);
   ~ThermoIntegrator();
};

#endif