#ifndef DOOR_H
#define DOOR_H

#include "SmartDevice.h"
#include "DoorState.h"

class Door :public SmartDevice
{
private:
   DoorState* state;
   string type;
public:
   Door();
   ~Door();
   string getType();
   DoorState* getStatus();
   void setStatus(DoorState* state);
   void update(); // for observer to be updated based on what the sensor found. Sensor will notify then update
   // motion sensor will be used such that when the user is close to the door, unlock.
   void lock();
   void unlock();
};



#endif