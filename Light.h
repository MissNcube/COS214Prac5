#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"
#include "LightState.h"

class Light : public SmartDevice
{
private:
   LightState* state;
   string type;
public:
   Light(/* args */);
   ~Light();
   void setState(LightState* state);
   LightState* getStatus();
   string getType();
   void update(); // sensor will notify light to change when someone walks in the room.
   void toggle(); // toggle between on and off state
};



#endif