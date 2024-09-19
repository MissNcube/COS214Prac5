#include "MacroRoutine.h"

MacroRoutine::~MacroRoutine()
{
   // Nothing to do here
}

void MacroRoutine::addCommand(Command *command)
{
   if(command != NULL) {
      commands.push_back(command);
   }
}

void MacroRoutine::removeCommand(Command *command)
{
   if(command != NULL) {
      for(int i = 0; i < commands.size(); i++) {
         if(commands[i] == command) {
            commands.erase(commands.begin() + i);
         }
      }
   }
}

void MacroRoutine::execute()
{
   cout << "||Macro routine executing||" << endl;
   for(int i = 0; i < commands.size(); i++) {
      commands[i]->execute();
   }
   cout << "||Macro routine done||" << endl;
}
