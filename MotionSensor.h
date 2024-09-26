#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H
#include <iostream>
using namespace std;
#include "Device.h"
#include "SmartDevice.h"
#include "Sensor.h"
class MotionSensor : public Sensor
{
private:
   /* data */
public:
   MotionSensor(/* args */);
   ~MotionSensor();
   void detectChange() override; // TODO: creativity needed
};



#endif
