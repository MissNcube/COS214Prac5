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

   /*
     if (dynamic_cast<LightOff*>(state)) {
         state->on(this);  // If the light is off, turn it on
      } else if (dynamic_cast<LightOn*>(state)) {
         state->off(this); // If the light is on, turn it off
      }
   */

};



#endif