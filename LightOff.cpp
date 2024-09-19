#include "LightOff.h"
#include "LightOn.h"
#include "Light.h"

LightOff::LightOff()
{
   this->name = "On";
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
