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
   if (this->state)
   {
      delete this->state; // Clean up state on destruction
   }
}

string Thermostat::getStatus()
{
   return this->state->toString();
}

string Thermostat::getType()
{
   return this->type;
}

void Thermostat::setStatus(ThermostatState *state)
{
   if (this->state)
   {
      delete this->state;
   }
   this->state = state;
}

void Thermostat::display()
{
   cout << "======\n";
   cout << "Device type: " << this->getType() << endl;
   cout << "Current temperature: " << this->getTemperature() << endl;
   cout << "Current state: " << this->getStatus() << endl;
   cout << "======\n";
}

/**
 * @brief Reacts to changes received from a connected sensor.
 * 
 * This method is called when the sensor notifies the thermostat of an update.
 * The thermostat checks the current temperature and adjusts its state accordingly:
 * - If the temperature is below 15°C, it switches to heating mode.
 *   @see ThermostatState::heat()
 * - If the temperature is above 32.5°C, it switches to cooling mode.
 *   @see ThermostatState::cool()
 * - If the temperature is within a comfortable range, it idles.
 *   @see ThermostatState::idle()
 * 
 * The current state and temperature are then displayed.
 */
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
