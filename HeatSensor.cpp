#include "HeatSensor.h"

HeatSensor::HeatSensor()
{
}

HeatSensor::~HeatSensor()
{
}

void HeatSensor::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void HeatSensor::removeDevice(SmartDevice * device)
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

void HeatSensor::notifyDevices()
{
    for (auto d : devices)
    {
        d->update();
    }
}

void HeatSensor::detectChange()
{
    cout << "Heat detected! Notifying all connected devices" << endl;
    notifyDevices();
}
