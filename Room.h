#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include "Device.h"
#include "SmartDevice.h"

class SmartDevice;
#include <vector>
#include <string>
using namespace std;

#include "Sensor.h"
class Room: public Device
{
private:
   vector<SmartDevice*> devices;
   string name;
public:
   Room(string name);
   void addDevice(SmartDevice* device);
   void removeDevice(SmartDevice* device);
   void display(); // display all devices
   void turnOn(); // command to turn on all devices in the room
   void turnOff(); // command to turn off all devices in the room
   void lock(); // lock all doors in the room
   void unlock(); // unlock all doors in the room



};




#endif