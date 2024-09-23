#include "Room.h"

Room::Room(string name)
{
    this->name = name;
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
        for(int i = 0; i < devices.size(); i++)
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

}

void Room::turnOff()
{
    cout << "Turn off  all devices in room: " << name << endl;
        for (SmartDevice* device : devices) {
        device->turnOff();  // Calls the turnOff method of each device
}
