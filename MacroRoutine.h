#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include "Command.h"
#include <vector>
#include <iostream>
using namespace std;


class MacroRoutine
{
private:
  vector<Command*> commands;
public:
   void addCommand(Command* command);
   void removeCommand(Command* command);
   void execute(); // run commands in sequence

};


#endif