#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include "Device.h"
#include <string>
using namespace std;

#include "Sensor.h"
class SmartDevice : public Device
{
private:

public:
  virtual string getType() = 0;
  virtual void update() = 0;
  virtual void display() = 0;
  virtual string getStatus() = 0;
  virtual ~SmartDevice() {}
};



#endif