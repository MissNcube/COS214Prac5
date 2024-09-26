#include "Sensor.h"

Sensor::~Sensor()
{
}

void Sensor::addDevice(SmartDevice *device)
{
    devices.push_back(device);
}

void Sensor::removeDevice(SmartDevice *device)
{
    devices.erase(remove(devices.begin(), devices.end(), device), devices.end());
}

void Sensor::notifyDevices()
{
    for (SmartDevice *d : devices)
    {
        d->update();
    }
}
