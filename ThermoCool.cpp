#include "ThermoCool.h"
#include "ThermoHot.h"
#include "ThermoIdle.h"
#include "Thermostat.h"

ThermoCool::ThermoCool()
{
   this->name = "Cool";
}

void ThermoCool::cool(Thermostat *thermostat)
{
   cout << "|Thermostat already cool|" << endl;
   thermostat->setTemperature(thermostat->getTemperature() - 10);
}

void ThermoCool::heat(Thermostat *thermostat)
{
   cout << "|Thermostat already cool, heating up|" << endl;
   thermostat->setTemperature(thermostat->getTemperature() + 10);
   thermostat->setStatus(new ThermoHot());
}

void ThermoCool::idle(Thermostat *thermostat)
{
   cout << "|Thermostat already cool, idle|" << endl;
   thermostat->setStatus(new ThermoIdle());
}

string ThermoCool::toString()
{
   return this->name;
}
