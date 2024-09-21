#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include "Command.h"
#include <vector>
#include <iostream>
using namespace std;
#include <string>


class MacroRoutine
{
private:
  vector<Command*> commands;
  string name;
public:
  MacroRoutine(string name);
   void addCommand(Command* command);
   void removeCommand(Command* command);
   void execute(); // run commands in sequence

};


#endif