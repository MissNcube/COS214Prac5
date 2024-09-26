#ifndef LOCKDOWN_H
#define LOCKDOWN_H

#include "Command.h"
#include "Door.h"
#include <vector>
using namespace std;
class LockDown : public Command
{
private:
   vector<Door*> doors;
public:
   ~LockDown();
   void execute();
   void addDoor(Door* door);
   void removeDoor(Door* door);
};



#endif