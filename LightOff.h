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
   void on(Light* light);
    void off(Light* light);
    string toString();

};



#endif