#ifndef TOGGLEALLLIGHTS_H
#define TOGGLEALLLIGHTS_H

#include "Command.h"
#include "SmartDevice.h"
#include <vector>
using namespace std;

class ToggleAllLights : public Command
{
private:
   vector<SmartDevice*> devices;
public:
   ToggleAllLights(/* args */);
   ~ToggleAllLights();
   void execute();
   void addLights(SmartDevice* light);
   void removeLights(SmartDevice* light);
};


#endif