#ifndef DOORLOCKED_H
#define DOORLOCKED_H

#include "DoorState.h"
#include <string>
#include <iostream>
using namespace std;
class Door;

class DoorLocked : public DoorState
{
private:
   string name;
public:
   DoorLocked();
  void lock(Door* door);
   void unlock(Door* door);
   string getStatus();
   
   };




#endif