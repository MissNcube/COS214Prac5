#ifndef TOGGLEALLLIGHTS_H
#define TOGGLEALLLIGHTS_H

#include "Command.h"
#include "Light.h"
#include <iostream>
#include <vector>
using namespace std;

class ToggleAllLights : public Command
{
private:
   vector<Light*> lights;
public:
   ~ToggleAllLights();
   void execute();
   void addLights(Light* light);
   void removeLights(Light* light);
};


#endif