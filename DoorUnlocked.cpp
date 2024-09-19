#include "DoorUnlocked.h"
#include "DoorLocked.h"
#include "Door.h"

DoorUnlocked::DoorUnlocked()
{
   this->name = "Unlocked";
}

void DoorUnlocked::lock(Door *door)
{
   cout << "|Locking door|" << endl;
   door->setStatus(new DoorLocked());
}

void DoorUnlocked::unlock(Door *door)
{
   cout << "|Door already unlocked|" << endl;
}

string DoorUnlocked::toString()
{
   return name;
}
