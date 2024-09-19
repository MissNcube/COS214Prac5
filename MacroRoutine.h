#ifndef MACROROUTINE_H
#define MACROROUTINE_H

#include "Command.h"
#include <vector>
using namespace std;

class MacroRoutine: public Command
{
private:
  vector<Command*> commands;
public:
   MacroRoutine(/* args */);
   ~MacroRoutine();
   void addCommand(Command* command);
   void removeCommand(Command* command);
   void execute(); // run commands in sequence

};


#endif