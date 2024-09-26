#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <string>
using namespace std;
#include "SmartDevice.h"
class SmartDevice;


class Sensor // SUBJECT???
{
private:
   vector<SmartDevice*> devices;
public:
   virtual void addDevice(SmartDevice* device) = 0;
   virtual void removeDevice(SmartDevice* device) = 0;
   virtual void notifyDevices() = 0;
   virtual void detectChange() = 0;
};


#endif