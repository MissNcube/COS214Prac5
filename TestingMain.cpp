#include "SmartDevice.h"
#include "Light.h"
#include "Door.h"
#include "Device.h"
#include "Thermostat.h"
#include "ThermoCool.h"
#include "ThermoHot.h"
#include "ThermoIdle.h"
#include "ThermostatState.h"
#include <iostream>
#include "Light.h"
#include "LightOn.h"
#include "LightOff.h"
#include "LightState.h"
#include "DoorLocked.h"
#include "DoorUnlocked.h"
#include "DoorState.h"


void testStates() {
   cout << "==================Testing States==================\n";
   // Create a new Light object (starts in OffState)
      cout << "##############Testing Light States##############\n";

    Light* myLight = new Light();

    // Print the initial state
    myLight->display();

    // Toggle the light (should turn it on)
    myLight->toggle();
    myLight->display();

    // Toggle again (should turn it off)
    myLight->toggle();
    myLight->display();
   
   cout << endl;
   cout << "##############Testing Door States##############\n";

   Door* myDoor = new Door();
   myDoor->display();
   myDoor->lock();
   myDoor->display();
   myDoor->unlock();
   myDoor->display();


   cout << endl;
   cout << "##############Testing Thermostat States##############\n";

   Thermostat* myThermo =  new Thermostat();
   myThermo->display();
   myThermo->cool();
   myThermo->display();
   myThermo->heat();

   myThermo->setTemperature(35);
   myThermo->display();
   myThermo->setTemperature(15);
   myThermo->display();
   myThermo->idle();

}
int main() {
   testStates();
}