#include "MotionSensor.h"

MotionSensor::MotionSensor()
{
}

MotionSensor::~MotionSensor()
{
}


void MotionSensor::detectChange()
{
    cout << "Motion detected! Notifying all connected devices" << endl;
    notifyDevices();
}
