#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#include "SmartDevice.h"
#include "Device.h"
class SmartDevice;


class Sensor // SUBJECT???
{
private:
   vector<SmartDevice*> devices;
public:
   ~Sensor();
   virtual void addDevice(SmartDevice* device);
   virtual void removeDevice(SmartDevice* device);
   virtual void notifyDevices();
   virtual void detectChange() = 0;
};


#endif