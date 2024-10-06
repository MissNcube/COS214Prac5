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

/**
 * @brief Notifies all connected devices of a change.
 * 
 * This method iterates through the list of connected smart devices and calls the
 * `update()` method on each device. It ensures that only non-null devices are notified.
 * This is typically used to inform devices of changes detected by the sensor.
 * 
 * @see SmartDevice::update() for details on how devices respond to notifications.
 */
void Sensor:: notifyDevices()
{
    for (SmartDevice *d : devices)
    {
        if(d)
            d->update();
    }
}
