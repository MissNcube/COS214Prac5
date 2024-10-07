#include "ThermoIntegrator.h"
#include "Thermostat.h"
#include "ThermoCool.h"
#include "ThermoIdle.h"
#include "ThermostatState.h"

/**
 * @brief Constructs a ThermoIntegrator instance.
 * 
 * This constructor initializes the ThermoIntegrator with a given legacy thermostat
 * and sets the initial state to ThermoIdle.
 * 
 * @param legacy A pointer to a 'LegacyThermostat' object that this integrator will manage.
 * 
 * @note The initial state is set to ThermoIdle, which indicates that the system is not currently active.
 */
ThermoIntegrator::ThermoIntegrator(LegacyThermostat *legacy)
{
   this->legacyThermostat =  legacy;
   this->currentState = new ThermoIdle();
}

ThermoIntegrator::~ThermoIntegrator()
{
   if(currentState) {
      delete currentState;
   }
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

string ThermoIntegrator::getStatus()
{
   return this->currentState->toString();
}

void ThermoIntegrator::cool()
{
   this->legacyThermostat->activateCooling();
   currentState->cool(this);
}

void ThermoIntegrator::heat()
{
   this->legacyThermostat->activateHeating();
   currentState->heat(this);
}

void ThermoIntegrator::idle()
{
   this->legacyThermostat->deactivateSystem();
   currentState->idle(this);
}
