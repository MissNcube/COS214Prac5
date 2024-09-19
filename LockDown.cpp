#include "LockDown.h"

LockDown::~LockDown()
{
   for(int i = 0; i < doors.size(); i++) {
      if(doors[i] != NULL) {
         delete doors[i];
         doors[i] = NULL;
      }
   }
   delete this;

}

void LockDown::execute()
{
   for(int i = 0; i < doors.size(); i++) {
      doors[i]->lock(); //should lock doors
   }
}

void LockDown::addDoor(Door *door)
{
   if(door != NULL) {
      doors.push_back(door);
   }
}

void LockDown::removeDoor(Door *door)
{
   if(door != NULL) {
      for(int i = 0; i < doors.size(); i++) {
         if(doors[i] == door) {
            doors.erase(doors.begin() + i);
         }
      }
   }

}
