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
   LegacyThermostat(/* args */);
   ~LegacyThermostat();
   void setTemp(double temp);
   double getTemp();

};


#endif