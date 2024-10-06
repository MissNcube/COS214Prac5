#include "UnlockDoors.h"

UnlockDoors::~UnlockDoors()
{
   // for(Door* d: doors) {
   //    if(d != NULL) {
   //       delete d;
   //       d =  NULL;
   //    }
   // }

  // delete this;
}

/**
 * @brief Unlocks all doors.
 * 
 * This method iterates through all the doors managed by the 
 * `UnlockDoors` object and calls the `unlock()` method on each door 
 * that is not null. It also outputs messages to indicate when the 
 * unlocking starts and ends.
 * 
 * @note Only non-null doors will be unlocked.
 * 
 * @see Door::unlock() for the method that changes the state of a door.
 * @see UnlockDoors::addDoor() for adding doors to the unlock list.
 * @see UnlockDoors::removeDoor() for removing doors from the unlock list.
 */
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
