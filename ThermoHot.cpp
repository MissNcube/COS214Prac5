#include "ThermoHot.h"
#include "Thermostat.h"
#include "ThermoCool.h"
#include "ThermoIdle.h"

ThermoHot::ThermoHot()
{
   this->name = "Hot";
}

void ThermoHot::cool(Thermostat *thermostat)
{
   cout << "|Thermostat cooling down|" << endl;
   thermostat->setTemperature(thermostat->getTemperature() - 10);
   thermostat->setStatus(new ThermoCool());
}

void ThermoHot::heat(Thermostat *thermostat)
{
   cout << "|Thermostat already hot :( |" << endl;
   thermostat->setTemperature(thermostat->getTemperature() + 10);
}

void ThermoHot::idle(Thermostat *thermostat)
{
   cout << "|Thermostat is already hot :) |" << endl;
   thermostat->setStatus(new ThermoIdle());
}

string ThermoHot::toString()
{
   return this->name;
}
