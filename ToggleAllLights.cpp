#include "ToggleAllLights.h"

ToggleAllLights::~ToggleAllLights()
{
   for(auto light: lights) {
      if(light != NULL) {
         delete light;
         light = NULL;
      }
   }
   delete this;
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
      for (int i = 0; i < lights.size(); i++)
      {
         if(lights[i] == light) {
            lights.erase(lights.begin() + i);
         }
      }
   }
}
