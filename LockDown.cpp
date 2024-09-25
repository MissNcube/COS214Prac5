#include "LockDown.h"

LockDown::~LockDown()
{
   // for(Door* door : doors) {
   //    if(door != NULL) {
   //       delete door;
   //       door = NULL;
   //    }
   // }
   //delete this;

}

void LockDown::execute()
{
   for(Door* door : doors) {
      door->lock(); //should lock doors
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
      int i = 0;
      for(Door* d : doors) {
         if(d == door) {
            doors.erase(doors.begin() + i);
         }
         i++;
      }
   }

}
