#include "AllLightsOff.h"


AllLightsOff::~AllLightsOff()
{
   // for(auto light: lights) {
   //    if(light != NULL) {
   //       delete light;
   //       light = NULL;
   //    }
   // }
   //delete this;
}
void AllLightsOff::execute()
{
   cout << "All lights are off" << endl;
   for(Light* light : lights) {
      if(light->getStatus() == "On") {
         light->toggle();
      }
   }
}

void AllLightsOff::addLights(Light *light)
{
   if(light != NULL) {
      lights.push_back(light);
   }
}

void AllLightsOff::removeLights(Light *light)
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
