#ifndef DOORSTATE_H
#define DOORSTATE_H

class Door;
#include <string>
using namespace std;

class DoorState
{
private:
   /* data */
public:
   /**
    * @brief Locks the door.
    * @param door Pointer to the Door to be locked.
    */
   virtual void lock(Door* door) = 0;
   /**
    * @brief Gets a string representation of the state.
    * @return String describing the door's state.
    */
   virtual void unlock(Door* door) = 0;
   virtual string toString() = 0;
   virtual ~DoorState();
};



#endif