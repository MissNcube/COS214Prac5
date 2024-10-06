#include "Light.h"
#include "LightOff.h"
#include "LightOn.h"
#include "LightState.h"

Light::Light()
{
   this->type = "Light";
   this->state = new LightOff();
}

Light::~Light()
{
   if (this->state)
   {
      delete this->state; // Clean up state on destruction
   } // delete this;
}

/**
 * @brief Sets a new state for the light.
 * 
 * This method updates the current state of the light by deleting 
 * the previous state and assigning a new one. It ensures that the 
 * light only has one active state at any time.
 * 
 * @param state Pointer to the new state object to be assigned to 
 * the light. It takes ownership of the new state and deletes 
 * the previous one if it exists.
 * 
 * @see LightState for the base class representing light states.
 */
void Light::setState(LightState *state)
{
   if (this->state)
   {
      delete this->state;
   }
   this->state = state;
}

string Light::getStatus()
{
   return this->state->toString();
}

/**
 * @brief Displays the current status of the light.
 * 
 * This method prints the type and current state of the light 
 * to the console. It provides a visual representation of the 
 * light's status for monitoring purposes.
 * 
 * @see Light::getType() for the type of the light.
 * @see Light::getStatus() for the current state of the light.
 */
void Light::display()
{
   cout << "======\n";
   cout << "Device type: " << this->getType() << endl;
   cout << "Device state: " << this->getStatus() << endl;
   cout << "======\n";
}

string Light::getType()
{
   return this->type;
}

/**
 * @brief Updates the light's state based on sensor input.
 * 
 * This method simulates receiving an update from a sensor, 
 * triggering a toggle of the light's current state. It outputs 
 * a message indicating that an update has been received.
 * 
 * @note This method assumes that the light's state will be 
 * toggled on each update.
 * 
 * @see Light::toggle() for the method that switches the light's state.
 */
void Light::update()
{
   cout << "Light: Received update from sensor!" << endl;
   this->toggle(); //switches on or off
}

void Light::toggle()
{
   state->toggle(this);
}
