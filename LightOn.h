#ifndef LIGHTON_H
#define LIGHTON_H


#include "LightState.h"
#include <iostream>
using namespace std;
class Light;
#include <string>


class LightOn : public LightState
{
private:
     string name;
public:
   LightOn();
   ~LightOn();
   void on(Light* light);
   void off(Light* light);

};



#endif