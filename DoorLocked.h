#ifndef DOORLOCKED_H
#define DOORLOCKED_H

#include "DoorState.h"

class DoorLocked : public DoorState
{
private:
   /* data */
public:
   DoorLocked(/* args */);
   ~DoorLocked();
  void lock(Door* door);
   void unlock(Door* door);
   
   };




#endif