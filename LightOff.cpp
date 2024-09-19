#include "LightOff.h"
#include "LightOn.h"
#include "Light.h"

LightOff::LightOff()
{
   this->name = "Off";
}



void LightOff::on(Light *light)
{
   cout << "|Turning light on|" << endl;
   light->setState(new LightOn());
}

void LightOff::off(Light *light)
{
   cout << "|Light already off|" << endl;
}

string LightOff::toString()
{
   return this->name;
}

void LightOff::toggle(Light *light)
{
   this->on(light);
}
