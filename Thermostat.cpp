#include "Thermostat.h"
#include "ThermoCool.h"
#include "ThermoIdle.h"
#include "ThermostatState.h"

Thermostat::Thermostat()
{
   this->type = "Thermostat";
   this->temperature = 20.0;
   this->state = new ThermoIdle();
}

Thermostat::~Thermostat()
{
   delete this->state;
   delete this;
}

ThermostatState *Thermostat::getStatus()
{
   return this->state;
}

string Thermostat::getType()
{
   return this->type;
}

void Thermostat::setStatus(ThermostatState *state)
{
   if(this->state) {
      delete this->state;
   }
   this->state = state;
}

void Thermostat::setTemperature(double temperature)
{
   this->temperature = temperature;
}

double Thermostat::getTemperature()
{
   return this->temperature;
}

void Thermostat::cool()
{
   this->state->cool(this);
}

void Thermostat::heat()
{
   this->state->heat(this);
}

void Thermostat::idle()
{
   this->state->idle(this);
}
