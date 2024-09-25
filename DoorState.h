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
   virtual void lock(Door* door) = 0;
   virtual void unlock(Door* door) = 0;
   virtual string toString() = 0;
   virtual ~DoorState();
};



#endif