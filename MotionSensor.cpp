#include "MotionSensor.h"

MotionSensor::MotionSensor()
{
}

MotionSensor::~MotionSensor()
{
}

void MotionSensor::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void MotionSensor::removeDevice(SmartDevice * device)
{
    for (auto it = devices.begin(); it != devices.end(); ++it)
    {
        if (*it == device)
        {
            devices.erase(it);
            break;
        }
    }
}

void MotionSensor::notifyDevices()
{
    for (auto d : devices)
    {
        if(d != nullptr)
        {
                    d->update();
        }

    }
}

void MotionSensor::detectChange()
{
    cout << "Motion detected! Notifying all connected devices" << endl;
    notifyDevices();
}
