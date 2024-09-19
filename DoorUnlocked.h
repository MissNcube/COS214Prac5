#ifndef DOORUNLOCKED_H
#define DOORUNLOCKED_H

#include "DoorState.h"

class DoorUnlocked :public DoorState
{
private:
   /* data */
public:
   DoorUnlocked(/* args */);
   ~DoorUnlocked();
   void lock(Door* door);
   void unlock(Door* door);
};


#endif