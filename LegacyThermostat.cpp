#include "LegacyThermostat.h"

LegacyThermostat::LegacyThermostat()
{
   this->type = "Legacy Thermostat";
   this->temperature = 20.0;
}

LegacyThermostat::~LegacyThermostat()
{
   
}

void LegacyThermostat::setTemp(double temp)
{
   this->temperature = temp;
}

double LegacyThermostat::getTemp()
{
   return this->temperature;
}

string LegacyThermostat::getType()
{
   return this->type;
}

void LegacyThermostat::activateCooling()
{
   cout << "Legacy Thermostat: Cooling activated" << endl;

}

void LegacyThermostat::activateHeating()
{
   cout << "Legacy Thermostat: Heating activated" << endl;
}

void LegacyThermostat::deactivateSystem()
{
   cout << "Legacy Thermostat: System deactivated" << endl;
}
