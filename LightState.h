#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H

class Light;
class LightState
{
private:

public:
   virtual void on(Light* light) = 0;
   virtual void off(Light* light) = 0;
   virtual string toString() = 0;
};


#endif