#include "AllLightsOn.h"


AllLightsOn::~AllLightsOn()
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
 * It ensures that all connected lights are turned on.
 * 
 * The method iterates over the list of lights and calls Light::toggle() on any light that is still off.
 * 
 * @see Light::getStatus()
 * @see Light::toggle()
 */
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
