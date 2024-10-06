#include "LightOn.h"
#include "LightOff.h"
#include "Light.h"

LightOn::LightOn()
{
   this->name = "On";
}

LightOn::~LightOn()
{
  // delete this;
}

/**
 * @brief Handles the action when the light is already on.
 * 
 * This method is called when an attempt is made to turn on a light 
 * that is already in the "On" state. It outputs a message indicating 
 * that the light is already on and does not change the state.
 * 
 * @param light Pointer to the Light object that is being acted upon.
 * 
 * @see LightOn::off() for turning off the light.
 */
void LightOn::on(Light* light)
{
   cout << "|Light already on|" << endl;
}

/**
 * @brief Turns the light off and changes its state.
 * 
 * This method handles the action of turning off the light. It outputs 
 * a message indicating that the light has been turned off and changes 
 * the light's state to LightOff.
 * 
 * @param light Pointer to the Light object that is being acted upon.
 * 
 * @see LightOn::on() for turning on the light.
 * @see LightOff for the new state assigned to the light.
 */
void LightOn::off(Light* light)
{
   cout << "|Light turned off|" << endl;
   light->setState(new LightOff());
}

string LightOn::toString()
{
   return this->name;
}

void LightOn::toggle(Light *light)
{
   this->off(light);
}
