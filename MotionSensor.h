#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include "Sensor.h"
class MotionSensor : public Sensor
{
private:
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
