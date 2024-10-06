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

/**
 * @brief Increases the temperature of the thermostat when it is already hot.
 * 
 * This method is called when an attempt is made to heat the thermostat 
 * that is already in the "Hot" state. It outputs a message indicating 
 * that the thermostat is already hot and increases its temperature by 
 * 10 degrees.
 * 
 * @param thermostat Pointer to the Thermostat object that is being acted upon.
 * 
 * @see ThermoHot::cool() for cooling the thermostat.
 * @see ThermoHot::idle() for changing the state to idle.
 */
void ThermoHot::heat(Thermostat *thermostat)
{
   cout << "|Thermostat already hot :( |" << endl;
   thermostat->setTemperature(thermostat->getTemperature() + 10);
}

void ThermoHot::idle(Thermostat *thermostat)
{
   cout << "|Thermostat is already hot :), idling |" << endl;
   thermostat->setStatus(new ThermoIdle());
}

string ThermoHot::toString()
{
   return this->name;
}
