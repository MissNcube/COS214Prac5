#ifndef COMMAND_H
#define COMMAND_H

class Command
{
private:

public:
   /**
    * @brief Executes the command.
    * 
    * This pure virtual function must be implemented by derived classes 
    * to define the specific behavior of the command.
    */
   virtual void execute() = 0; // pure virtual function
   virtual ~Command() {}
};



#endif