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

void Door::update()
{
}

void Door::lock()
{
   this->state->lock(this);
}

void Door::unlock()
{
   this->state->unlock(this);
}
