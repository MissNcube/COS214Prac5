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

void LightOn::on(Light* light)
{
   cout << "|Light already on|" << endl;
}

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
