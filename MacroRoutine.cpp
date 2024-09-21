#include "MacroRoutine.h"

MacroRoutine::MacroRoutine(string name)
{
   this->name =  name;
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
      int i = 0;
      for(Command* c : commands) {
         if(c == command) {
            commands.erase(commands.begin() + i);
         }
         i++;
      }
   }
}

void MacroRoutine::execute()
{
   cout << "||Macro routine: "<< this->name <<" executing||" << endl;
   for(Command* c : commands) {
      c->execute();
   }
   cout << "||Macro routine done||" << endl;
}
