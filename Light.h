#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include "LightState.h"
#include <iostream>
#include <string>
using namespace std;

class Light : public SmartDevice
{
private:
   LightState* state;
   string type;
public:
   Light();
   ~Light();
   void setState(LightState* state);
   string getStatus();
   void display();
   string getType();
   void update(); // sensor will notify light to change when someone walks in the room.
   void toggle(); // toggle between on and off state
};



#endif