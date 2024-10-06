#include "Door.h"
#include "DoorLocked.h"
#include "DoorUnlocked.h"

Door::Door()
{
   this->type = "Door";
   this->state = new DoorUnlocked();
}

Door::~Door()
{

   if (this->state)
   {
      delete this->state; // Clean up state on destruction
   }
}

string Door::getType()
{
   return this->type;
}

string Door::getStatus()
{
   return this->state->toString();
}

void Door::setStatus(DoorState *state)
{
   if (this->state)
   {
      delete this->state;
   }

   this->state = state;
}

void Door::display()
{
   cout << "======\n";
   cout << "Device type: " << this->type << endl;
   cout << "Device Status: " << this->getStatus() << endl;
   cout << "======\n";
}

/**
 * @brief Reacts to updates received from the sensor.
 * 
 * This method is called when a sensor detects an event (e.g., motion). It determines the door's current state
 * and reacts accordingly. 
 * 
 * - If the door is unlocked and no motion is detected, the door will be locked by calling the lock() method.
 * - If the door is locked and motion is detected, the door will be unlocked by calling the unlock() method.
 * 
 * After the action is taken, the method displays the current state of the door using the display() method.
 * 
 * @see DoorState::lock()
 * @see DoorState::unlock()
 * @see Door::display()
 */
void Door::update()
{
   cout << "Door: Received update from sensor!" << endl;

   if(dynamic_cast<DoorUnlocked*>(this->state)) // If the door is unlocked
   {
      cout << "No motion detected nearby. Locking the door..." << endl;
      this->lock();  //lock door if no one close by
   }
   else  //if door unlocked
   {
      cout << "Motion detected! Unlocking the door..." << endl;
      this->unlock(); //unlcok it
   }

   display(); //display what curr state of door is 
}

void Door::lock()
{
   this->state->lock(this);
}

void Door::unlock()
{
   this->state->unlock(this);
}
