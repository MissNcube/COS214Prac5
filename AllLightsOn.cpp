#include "AllLightsOn.h"


AllLightsOn::~AllLightsOn()
{
   for(auto light: lights) {
      if(light != NULL) {
         delete light;
         light = NULL;
      }
   }
   delete this;
}
void AllLightsOn::execute()
{
   cout << "All lights are on" << endl;
   for(Light* light : lights) {
      if(light->getStatus() == "Off") {
         light->toggle();
      }
   }
}

void AllLightsOn::addLights(Light *light)
{
   if(light != NULL) {
      lights.push_back(light);
   }
}

void AllLightsOn::removeLights(Light *light)
{
   if(light != NULL) {
      int i = 0;
      for(Light* l: lights) {
         if(l == light) {
            lights.erase(lights.begin() + i);
         }
         i++;
      }
   }
}
