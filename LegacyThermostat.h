#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H


#include <string>
#include <iostream>
using namespace std;
class LegacyThermostat // ADAPTEE
{
private:
   double temperature;
   string type;
public:
   LegacyThermostat();
   ~LegacyThermostat();
   void setTemp(double temp);
   double getTemp();
   string getType();
   void activateCooling();
   void activateHeating();
   void deactivateSystem();

};


#endif