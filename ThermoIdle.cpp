#include "ThermoIdle.h"
#include "Thermostat.h"
#include "ThermoCool.h"
#include "ThermoHot.h"

ThermoIdle::ThermoIdle()
{
   this->name = "Idle";
}

void ThermoIdle::cool(Thermostat *thermostat)
{
   cout << "|Thermostat cooling down" << endl;
   thermostat->setTemperature(thermostat->getTemperature() - 10);
   thermostat->setStatus(new ThermoCool());
}

void ThermoIdle::heat(Thermostat *thermostat)
{
   cout << "|Thermostat heating up|" << endl;
   thermostat->setTemperature(thermostat->getTemperature() + 10);
   thermostat->setStatus(new ThermoHot());
}

void ThermoIdle::idle(Thermostat *thermostat)
{
   cout << "|Thermostat doing nothing rn, idling|" << endl;
}

string ThermoIdle::toString()
{
   return this->name;
}
