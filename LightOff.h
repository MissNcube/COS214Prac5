#ifndef LIGHTOFF_H
#define LIGHTOFF_H

#include "LightState.h"
#include <iostream>
#include <string>
using namespace std;
class Light;
class LightOff : public LightState
{
private:
   string name;
public:
   LightOff();
   ~LightOff();
   void on(Light* light);
    void off(Light* light);

};



#endif