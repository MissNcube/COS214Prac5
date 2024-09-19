#ifndef UNLOCKDOORS_H
#define UNLOCKDOORS_H

#include "Command.h"
#include "Door.h"
#include <vector>
#include <iostream>
using namespace std;


class UnlockDoors : public Command
{
private:
   vector<Door*> doors;
public:
   UnlockDoors(/* args */);
   ~UnlockDoors();
   void execute();
   void addDoor(Door* door);
   void removeDoor(Door* door);
};




#endif