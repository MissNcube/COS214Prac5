#ifndef DOORUNLOCKED_H
#define DOORUNLOCKED_H

#include "DoorState.h"
#include <string>
#include <iostream>
using namespace std;
class Door;

class DoorUnlocked :public DoorState
{
private:
   string name;
public:
   DoorUnlocked();
   ~DoorUnlocked();
   void lock(Door* door);
   void unlock(Door* door);
   string toString();
};


#endif