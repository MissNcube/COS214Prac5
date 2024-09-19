#ifndef LIGHTON_H
#define LIGHTON_H


#include "LightState.h"

class LightOn : public LightState
{
private:
   /* data */
public:
   LightOn(/* args */);
   ~LightOn();
    void on();
    void off();

};

}

#endif