#ifndef UNLOCKDOORS_H
#define UNLOCKDOORS_H

#include "Command.h"
#include "SmartDevice.h"
#include <vector>
using namespace std;


class UnlockDoors : public Command
{
private:
   vector<SmartDevice*> doors;
public:
   UnlockDoors(/* args */);
   ~UnlockDoors();
   void execute();
   void addDoor(SmartDevice* door);
   void removeDoor(SmartDevice* door);
};




#endif