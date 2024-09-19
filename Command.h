#ifndef COMMAND_H
#define COMMAND_H

#include "SmartDevice.h"

class Command
{
private:
   /* data */
public:
   Command(/* args */);
   ~Command();
   virtual void execute() = 0; // pure virtual function
};



#endif