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
   vector<SmartDevice*> devices;
   /* data */
public:
   MotionSensor(/* args */);
   ~MotionSensor();
   void addDevice(SmartDevice* device);
   void removeDevice(SmartDevice* device);
   void notifyDevices();
   void detectChange(); // TODO: creativity needed

};



#endif
