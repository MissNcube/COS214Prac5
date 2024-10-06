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

/**
 * @brief Executes the "All Lights Off" command.
 * 
 * This method checks the status of each light in the list and toggles it off if it is currently "On."
 * It ensures that all connected lights are turned off.
 * 
 * The method iterates over the list of lights and calls Light::toggle() on any light that is still on.
 * 
 * @see Light::getStatus()
 * @see Light::toggle()
 */

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
