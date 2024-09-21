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
#include "Command.h"
#include "MacroRoutine.h"
#include "LockDown.h"
#include "ToggleAllLights.h"
#include "UnlockDoors.h"
#include "AllLightsOff.h"
#include "AllLightsOn.h"


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


void testCommand() {
   cout << "==================Testing Command==================\n";

    // Create some light and door objects
    Light* livingRoomLight = new Light();
    Light* kitchenLight = new Light();

    Door* frontDoor = new Door();
    Door* backDoor = new Door();

    // Create command objects
    ToggleAllLights* toggleLightsCmd = new ToggleAllLights();
    toggleLightsCmd->addLights(livingRoomLight);
    toggleLightsCmd->addLights(kitchenLight);

    LockDown* lockDoorsCmd = new LockDown();
    lockDoorsCmd->addDoor(frontDoor);
    lockDoorsCmd->addDoor(backDoor);

    UnlockDoors* unlockDoorsCmd = new UnlockDoors();
    unlockDoorsCmd->addDoor(frontDoor);
    unlockDoorsCmd->addDoor(backDoor);

    AllLightsOn* lightsOn = new AllLightsOn();
    lightsOn->addLights(livingRoomLight);
    lightsOn->addLights(kitchenLight);

    AllLightsOff* lightsOff = new AllLightsOff();
    lightsOff->addLights(livingRoomLight);
    lightsOff->addLights(kitchenLight);

    // Create a macro routine and add commands to it
    MacroRoutine* goodeveningRoutine = new MacroRoutine("Welcome Back");
    goodeveningRoutine->addCommand(lightsOn);  // Turn off all lights
    goodeveningRoutine->addCommand(unlockDoorsCmd);     // Lock all doors

    cout << "\nExecuting Goodnight Routine...\n";
    goodeveningRoutine->execute();  // Execute all commands in the routine

    cout << "\nExecuting locking Doors Command...\n";
    lockDoorsCmd->execute();    // Manually execute the unlock command

   MacroRoutine* goodnightRoutine = new MacroRoutine("GoodNight");
    goodnightRoutine->addCommand(lightsOff);  // Turn off all lights
    goodnightRoutine->addCommand(lockDoorsCmd);     // Lock all doors

    cout << "\nExecuting Goodnight Routine...\n";
    goodnightRoutine->execute();  // Execute all commands in the routine

    cout << "\nExecuting Unlock Doors Command...\n";
    unlockDoorsCmd->execute();  

    cout << "\nExecuting Toggle Lights Command...\n";
    toggleLightsCmd->execute();
   cout << "\nExecuting Toggle Lights Command... again\n";
   toggleLightsCmd->execute();

}

int main() {
  // testStates();
   testCommand();
}