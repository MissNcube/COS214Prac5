#include "UnlockDoors.h"

UnlockDoors::~UnlockDoors()
{
   for(int i = 0; i < doors.size(); i++) {
      if(doors[i] != NULL) {
         delete doors[i];
         doors[i] =  NULL;
      }
   }

   delete this;
}

void UnlockDoors::execute()
{
   cout << "||Unlocking all doors||" << endl;
   for(int i = 0; i < doors.size(); i++) {
      if(doors[i] != NULL) {
         doors[i]->unlock();
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
   for(int i = 0; i < doors.size(); i++) {
      if(doors[i] == door) {
         doors.erase(doors.begin() + i);
      }
   }
}
