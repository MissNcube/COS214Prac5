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
   delete this->state;
   delete this;
}

string Door::getType()
{
   return this->type;
}

DoorState *Door::getStatus()
{
   return this->state;
}

void Door::setStatus(DoorState *state)
{
   if(this->state) {
      delete this->state;
   }

   this->state = state;
}

void Door::display()
{
   cout << "======\n";
   cout << "Device type: " << this->type << endl;
   cout << "Device Status: " << this->getStatus()->toString() << endl;
   cout << "======\n";
}

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
