#ifndef HEATSENSOR_H
#define HEATSENSOR_H

#include "Sensor.h"

class HeatSensor : public Sensor
{
private:
   /* data */
public:
   HeatSensor(/* args */);
   ~HeatSensor();
   void addDevice(SmartDevice* device);
   void removeDevice(SmartDevice* device);
   void notifyDevices();
   void detectChange();

};



#endif