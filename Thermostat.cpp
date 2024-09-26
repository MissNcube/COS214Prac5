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

void Thermostat::display()
{
   cout << "======\n";
   cout << "Device type: " << this->getType() << endl;
   cout << "Current temperature: " << this->getTemperature() << endl;
   cout << "Current state: " << this->getStatus()->toString() << endl;
   cout << "======\n";
}

void Thermostat::update()
{
      //react to sensor data
   cout << "Thermostat: Received update from sensor!" << endl;


   if (temperature <= 15.0) {     //cold
      cout << "It's too cold, heating..." << endl;
      this->heat();  //heat up
   } 
   else if (temperature > 32.5) {   //too hot
      cout << "It's too hot, cooling..." << endl;
      this->cool();  //cool down
   } 
   else {
      cout << "Temperature is comfortable, idling..." << endl;
      this->idle();  //nice temp in here
   }

   display();  //show state
}

void Thermostat::setTemperature(double temperature)
{
   this->temperature = temperature;
   // if(temperature < 18.2) { // too hot, time to cool
   //    this->heat();
   // } else if(temperature > 32.5) {
   //    this->cool();
   // } else {
   //    this->idle();
   // }
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
