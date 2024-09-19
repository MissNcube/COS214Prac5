#ifndef DOORSTATE_H
#define DOORSTATE_H

class Door;

class DoorState
{
private:
   /* data */
public:
   DoorState(/* args */);
   ~DoorState();
   virtual void lock(Door* door) = 0;
   virtual void unlock(Door* door) = 0;
};



#endif