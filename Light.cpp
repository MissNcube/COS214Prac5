#include "Light.h"
#include "LightOff.h"
#include "LightOn.h"
#include "LightState.h"

Light::Light() 
{
   this->type =  "Light";
   this->state = new LightOff();
}

Light::~Light()
{
   delete this->state;
   delete this;
}

void Light::setState(LightState *state)
{
   if(this->state) {
      delete this->state;
   }
   this->state = state;
}

LightState *Light::getStatus()
{
   return this->state;
}

void Light::display()
{
   cout << "======\n";
   cout << "Device type: " << this->getType() << endl;
   cout << "Device state: " << this->state->toString() << endl;
   cout << "======\n";
}

string Light::getType()
{
   return this->type;
}

void Light::update()
{

}

void Light::toggle()
{
   // if (dynamic_cast<LightOff*>(state)) {
   //    state->on(this);  // If the light is off, turn it on
   // } else if (dynamic_cast<LightOn*>(state)) {
   //    state->off(this); // If the light is on, turn it off
   // }
}
