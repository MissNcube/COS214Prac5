#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H
#include <string>
using namespace std;

class Light;
class LightState
{
private:

public:
   virtual void on(Light* light) = 0;
   virtual void off(Light* light) = 0;
   virtual string toString() = 0;
   virtual void toggle(Light* light) = 0;
};


#endif