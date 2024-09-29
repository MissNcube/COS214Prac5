#ifndef HOMESECTION_H
#define HOMESECTION_H

#include <iostream>
#include "Room.h"
#include "Device.h"
class Room;
#include <vector>
#include <string>
using namespace std;

class HomeSection :public Device
{
private:
   vector<Room*> rooms;
   string name;
public:
   HomeSection(string name);
   virtual ~HomeSection();

   void addRoom(Room* room);
   void removeRoom(Room* room);
   void display(); // display all rooms
   void turnOn(); // command to turn on all lights in the rooms
   void turnOff(); // command to turn off all lights in the rooms
   void lock(); // lock all doors in the house
   void unlock(); // unlock all doors in the house

};




#endif