#ifndef LIGHTSTATE_H
#define LIGHTSTATE_H

class Light;

class LightState
{
private:
   /* data */
public:
   ~LightState();
   virtual void on() = 0;
   virtual void off() = 0;
};


#endif