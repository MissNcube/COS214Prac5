#include "DoorLocked.h"
#include "DoorUnlocked.h"
#include "Door.h"

DoorLocked::DoorLocked()
{
   this->name = "Locked";
}

void DoorLocked::lock(Door *door)
{
   cout << "|Door already locked|";
}

void DoorLocked::unlock(Door *door)
{
   cout << "|Unlocking door|";
   door->setStatus(new DoorUnlocked());
}

string DoorLocked::getStatus()
{
   return this->name;
}
