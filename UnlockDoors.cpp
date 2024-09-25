#include "UnlockDoors.h"

UnlockDoors::~UnlockDoors()
{
   for(Door* d: doors) {
      if(d != NULL) {
         delete d;
         d =  NULL;
      }
   }

  // delete this;
}

void UnlockDoors::execute()
{
   cout << "||Unlocking all doors||" << endl;
   for(Door* d: doors) {
      if(d != NULL) {
         d->unlock();
      }
   }
   cout << "||All doors unlocked||" << endl;

}

void UnlockDoors::addDoor(Door *door)
{
   if(door != NULL) {
      doors.push_back(door);
   }
}

void UnlockDoors::removeDoor(Door *door)
{
   int i = 0;
   for(Door* d: doors) {
      if(d == door) {
         doors.erase(doors.begin() + i);
      }
      i++;
   }
}
