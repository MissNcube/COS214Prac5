#ifndef COMMAND_H
#define COMMAND_H

class Command
{
private:

public:
   virtual void execute() = 0; // pure virtual function
   virtual ~Command() {}
};



#endif