#include "Room.h"

Room::Room(string name)
{
    this->name = name;
}

Room::~Room()
{
    for(Device* d : devices)
    {
        delete d;
    }
}

void Room::addDevice(SmartDevice *device)
{
    if(device)
    {
        devices.push_back(device);
    }
    else
        return;
}
void Room::removeDevice(SmartDevice *device)
{
    if(device)
    {
    for (size_t i = 0; i < devices.size(); i++)

        {
            if(devices[i] == device)
            {
                devices.erase(devices.begin() + i);
            }
        }
    }
}

void Room::display()
{
    std::cout << "Room: " << name << std::endl;
    for (SmartDevice* device : devices) {
        device->display();  // Calls the display method of each device
    }
}

void Room::turnOn()
{
    cout << "Turn on all devices in room: " << name << endl;
    for (SmartDevice* device : devices) {
        device->update();  // Calls the turnOn method of each device
    }
}

void Room::lock()
{
    cout << "Locking all doors in Room: " << name << endl;
    for (SmartDevice* device : devices)
    {
        // Assuming only "Door" devices respond to lock
        if (device->getType() == "Door")
        {
            device->update(); // Locking the door
        }
    }
}

void Room::unlock()
{
    cout << "Unlocking all doors in Room: " << name << endl;
    for (SmartDevice* device : devices)
    {
        // Assuming only "Door" devices respond to unlock
        if (device->getType() == "Door")
        {
            device->update(); // Unlocking the door
        }
    }
}

void Room::turnOff()
{
    cout << "Turn off all devices in room: " << name << endl;
        for (SmartDevice* device : devices) {
        device->update();  // Calls the turnOff method of each device
        }
}
