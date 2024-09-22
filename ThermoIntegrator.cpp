#include "ThermoIntegrator.h"
#include "Thermostat.h"
#include "ThermoCool.h"
#include "ThermoIdle.h"
#include "ThermostatState.h"


ThermoIntegrator::ThermoIntegrator(LegacyThermostat *legacy)
{
   this->legacyThermostat =  legacy;
   this->currentState = new ThermoIdle();
}

ThermoIntegrator::~ThermoIntegrator()
{
   delete legacyThermostat;
   delete currentState;
}

string ThermoIntegrator::getType()
{
   return this->legacyThermostat->getType();
}

void ThermoIntegrator::display()
{
    cout << "======\n";
   cout << "Device type: " << this->legacyThermostat->getType() << endl;
   cout << "Current temperature: " << this->legacyThermostat->getTemp() << endl;
   cout << "Current state: " << this->currentState->toString() << endl;
   cout << "======\n";
}

void ThermoIntegrator::setStatus(ThermostatState *state)
{
   if (currentState) {
      delete currentState;
   }
   currentState = state;
}

void ThermoIntegrator::update()
{
}

void ThermoIntegrator::setTemperature(double temperature)
{
   this->legacyThermostat->setTemp(temperature);
}

double ThermoIntegrator::getTemperature()
{
   return this->legacyThermostat->getTemp();
}

void ThermoIntegrator::cool()
{

}
