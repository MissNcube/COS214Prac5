#ifndef LOCKDOWN_H
#define LOCKDOWN_H

#include "Command.h"
#include "SmartDevice.h"
#include <vector>
using namespace std;
class LockDown : public Command
{
private:
   vector<SmartDevice*> doors;
public:
   LockDown(/* args */);
   ~LockDown();
   void execute();
   void addDoor(SmartDevice* door);
   void removeDoor(SmartDevice* door);
};



#endif