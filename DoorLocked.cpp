#include "DoorLocked.h"
#include "DoorUnlocked.h"
#include "Door.h"

DoorLocked::DoorLocked()
{
   this->name = "Locked";
}

void DoorLocked::lock(Door *door)
{
   cout << "|Door already locked|\n";
}

void DoorLocked::unlock(Door *door)
{
   cout << "|Unlocking door|\n";
   door->setStatus(new DoorUnlocked());
}

string DoorLocked::toString()
{
   return this->name;
}
