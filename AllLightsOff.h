#ifndef ALLLIGHTSOFF_H
#define ALLLIGHTSOFF_H

#include <iostream>
#include "Command.h"
#include "Light.h"
#include <vector>
using namespace std;

class AllLightsOff : public Command
{
private:
   vector<Light*> lights;
public:
   ~AllLightsOff();
   void execute();
   void addLights(Light* light);
   void removeLights(Light* light);
};



#endif