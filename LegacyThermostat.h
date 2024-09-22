#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H


#include <string>
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

};


#endif