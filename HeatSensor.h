#ifndef HEATSENSOR_H
#define HEATSENSOR_H
#include <iostream>
using namespace std;
#include "Sensor.h"
#include "Device.h"
#include "SmartDevice.h"
class HeatSensor : public Sensor
{
private:
   /* data */
   vector<SmartDevice*> devices;
public:
   HeatSensor(/* args */);
   ~HeatSensor();
   void addDevice(SmartDevice* device);
   void removeDevice(SmartDevice* device);
   void notifyDevices();
   void detectChange();

};



#endif