#ifndef ALLLIGHTSON_H
#define ALLLIGHTSON_H

#include <iostream>
#include "Command.h"
#include "Light.h"
#include <vector>
using namespace std;

class AllLightsOn : public Command
{
private:
   vector<Light*> lights;
public:
   ~AllLightsOn();
   void execute();
   void addLights(Light* light);
   void removeLights(Light* light);
};



#endif