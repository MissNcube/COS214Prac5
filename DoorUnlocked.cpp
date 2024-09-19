#include "DoorUnlocked.h"
#include "DoorLocked.h"
#include "Door.h"

DoorUnlocked::DoorUnlocked()
{
   this->name = "Locked";
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

string DoorUnlocked::getStatus()
{
   return name;
}
