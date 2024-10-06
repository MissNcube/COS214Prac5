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

/**
 * @brief Toggles the state of all lights.
 * 
 * This method iterates through all the lights managed by the 
 * `ToggleAllLights` object and calls the `toggle()` method on each one.
 * It also outputs messages to indicate when the toggling starts and ends.
 * 
 * @note If a light is currently on, it will be turned off and vice versa.
 * 
 * @see Light::toggle() for the method that changes the state of a light.
 * @see ToggleAllLights::addLights() for adding lights to the toggle list.
 * @see ToggleAllLights::removeLights() for removing lights from the toggle list.
 */
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
