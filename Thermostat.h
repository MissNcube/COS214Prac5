#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class ThermostatState;
class Thermostat : public SmartDevice
{
   private:
      ThermostatState* state;
      double temperature;
      string type;
   public:
      Thermostat(); // initial state is idle
      ~Thermostat();
      ThermostatState* getStatus();
      string getType();
      void setStatus(ThermostatState* state);
      void display();
      void update(); // when there is a temperature change, it will notify the thermostat to work
      void setTemperature(double temperature);
      double getTemperature();
      void cool();
      void heat();
      void idle();
      // be able to change state based on temperature
};



#endif