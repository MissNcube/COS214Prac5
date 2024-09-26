#include "HomeSection.h"

HomeSection::HomeSection(string name)
{
    this->name = name;
}

HomeSection::~HomeSection()
{
    for (auto room : rooms) {
        delete room;
    }
}

void HomeSection::addRoom(Room* room)
{
    rooms.push_back(room);
}

void HomeSection::removeRoom(Room *room)
{
    for (int i = 0; i < rooms.size(); i++)
    {
        if (rooms[i] == room)
        {
            rooms.erase(rooms.begin() + i);
            return;
        }
    }

}

void HomeSection::display()
{
    cout << "Home Section: " << name << endl;
    for (Room* r :  rooms)
    {
        r->display();
    }

}

void HomeSection::turnOn()
{
    cout << "Turning on all devices in the section: " << name << endl;
    for (Room* r :  rooms)
    {
        r->turnOn();
    }
}

void HomeSection::turnOff()
{
    cout << "Turning off all devices in the section: " << name << endl;
    for (Room* room : rooms) {
        room->turnOff();  // Turns on all devices in each room
    }
}

void HomeSection::lock()
{
    cout << "Locking all doors in the section: " << name << endl;
    for (Room* room : rooms) {
        room->lock();  // Locks all doors in each room
    }
}

void HomeSection::unlock()
{
    cout << "Unlocking all doors in the section: " << name << endl;
    for (Room* room : rooms) {
        room->unlock();  // Unlocks all doors in each room
    }
}
