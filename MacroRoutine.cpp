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

/**
 * @brief Executes the macro routine by executing all registered commands.
 * 
 * This method iterates through the list of commands stored in the commands vector
 * and calls the execute() method on each command. It first prints a message indicating
 * the start of the macro routine execution and, after all commands have been executed, 
 * it prints a message indicating that the macro routine is done.
 * 
 * @see Command::execute() for the implementation details of the command execution.
 */
void MacroRoutine::execute()
{
   cout << "||Macro routine: "<< this->name <<" executing||" << endl;
   for(Command* c : commands) {
      c->execute();
   }
   cout << "||Macro routine done||" << endl;
}
