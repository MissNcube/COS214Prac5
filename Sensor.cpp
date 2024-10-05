#include "Sensor.h"

Sensor::~Sensor()
{
    //devices.clear();
}


void Sensor::addDevice(SmartDevice *device)
{
     if (!device)
    {
        return;
    }
    devices.push_back(device);
}

void Sensor::removeDevice(SmartDevice *device)
{
    devices.erase(remove(devices.begin(), devices.end(), device), devices.end());
}

void Sensor:: notifyDevices()
{
    for (SmartDevice *d : devices)
    {
        if(d)
            d->update();
    }
}
