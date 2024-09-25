#include "ToggleAllLights.h"

ToggleAllLights::~ToggleAllLights()
{
   // for(auto light: lights) {
   //    if(light != NULL) {
   //       delete light;
   //       light = NULL;
   //    }
   // }
   //delete this;
}

void ToggleAllLights::execute()
{
   cout << "||Toggling all lights||" << endl;
   for (auto light : lights) {
      light->toggle();
   }
   cout << "||All lights toggled||" << endl;
}

void ToggleAllLights::addLights(Light *light)
{
   if(light != NULL) {
      lights.push_back(light);
   }
}

void ToggleAllLights::removeLights(Light *light)
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
