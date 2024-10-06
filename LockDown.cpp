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

/**
 * @brief Removes a door from the lockdown list.
 * 
 * This method removes the specified door from the doors collection if it is not a null pointer.
 * It iterates through the list of doors, searching for a matching door, and erases it from the
 * collection once found.
 * 
 * @param door A pointer to the Door object to be removed from the list. 
 * If the pointer is null, the method does nothing.
 */
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
