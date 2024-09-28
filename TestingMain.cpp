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
#include "ThermoIntegrator.h"
#include "LegacyThermostat.h"
#include "HeatSensor.h"
#include "MotionSensor.h"
#include "HomeSection.h"


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


   delete myDoor;
   delete myLight;
   delete myThermo;
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

   delete livingRoomLight;
   delete kitchenLight;
   delete frontDoor;
   delete backDoor;
   delete lockDoorsCmd;
   delete unlockDoorsCmd;
   delete lightsOn;
   delete lightsOff;
   delete toggleLightsCmd;
   delete goodeveningRoutine;
   delete goodnightRoutine;
   
}

void testIntegrator() {
   cout << "==================Testing Integrator==================\n";

   LegacyThermostat* legacyThermostat = new LegacyThermostat();

    // Create the adapter to make the legacy thermostat smart
   ThermoIntegrator* smartThermostat = new ThermoIntegrator(legacyThermostat);

   smartThermostat->display();
   smartThermostat->setTemperature(25);
   smartThermostat->display();

   smartThermostat->cool();
   smartThermostat->display();

   smartThermostat->heat();
   smartThermostat->display();

   smartThermostat->idle();
   smartThermostat->display();

   smartThermostat->heat();
   smartThermostat->heat();
   smartThermostat->heat();

   smartThermostat->display();

   delete smartThermostat;
   delete legacyThermostat;
}

void testComposite()
{
       // Create a home section (e.g., "Living Area")
    HomeSection* livingArea = new HomeSection("Living Area");

    // Create rooms (e.g., "Living Room" and "Bedroom")
    Room* livingRoom = new Room("Living Room");
    Room* bedroom = new Room("Bedroom");

    // Add rooms to the home section
    livingArea->addRoom(livingRoom);
    livingArea->addRoom(bedroom);

    // Create smart devices (lights and doors)
    SmartDevice* light1 = new Light();
    SmartDevice* light2 = new Light();

    SmartDevice* door1 = new Door();
    SmartDevice* door2 = new Door();

    // Add smart devices to rooms
    livingRoom->addDevice(light1);
    livingRoom->addDevice(door1);

    bedroom->addDevice(light2);
    bedroom->addDevice(door2);

    // Test display (should display the rooms and the devices inside)
    cout << "===== Displaying Home Section =====" << endl;
    livingArea->display();

    // Test turning on all lights in the home section
    cout << "\n===== Turning On All Lights =====" << endl;
    livingArea->turnOn();
    livingArea->display(); // Display status after turning on

    // Test turning off all lights in the home section
    cout << "\n===== Turning Off All Lights =====" << endl;
    livingArea->turnOff();
    livingArea->display(); // Display status after turning off

    // Test locking all doors in the home section
    cout << "\n===== Locking All Doors =====" << endl;
    livingArea->lock();
    livingArea->display(); // Display status after locking doors

    // Test unlocking all doors in the home section
    cout << "\n===== Unlocking All Doors =====" << endl;
    livingArea->unlock();
    livingArea->display(); // Display status after unlocking doors
}

void testObserver()
{
    // Create sensors
    HeatSensor* heatSensor = new HeatSensor();
    MotionSensor* motionSensor = new MotionSensor();

    // Create observers (devices)
    Thermostat* thermostat = new Thermostat();
    Door* door = new Door();

    // Subscribe thermostat to heat sensor
    heatSensor->addDevice(thermostat);

    // Subscribe door to motion sensor
    motionSensor->addDevice(door);

    // Simulate heat sensor detecting a temperature change
    cout << "\n===== Heat Sensor Detects a Temperature Change =====" << endl;
    thermostat->setTemperature(35.0); // High temperature
    heatSensor->detectChange(); // Notifies thermostat to update

    // Simulate motion sensor detecting motion near the door
    cout << "\n===== Motion Sensor Detects Motion =====" << endl;
    motionSensor->detectChange(); // Notifies door to update (e.g., unlock)

    // Simulate another temperature change
    cout << "\n===== Heat Sensor Detects Another Temperature Change =====" << endl;
    thermostat->setTemperature(15.0); // Low temperature
    heatSensor->detectChange(); // Thermostat will update to heat

    // Simulate motion sensor detecting no motion
    cout << "\n===== Motion Detected Near the Door =====" << endl;
    motionSensor->detectChange(); // Can lock the door
}

void testObserver2()
{
    // Create a thermostat
    Thermostat* thermostat = new Thermostat();

    // Simulate different temperatures
    thermostat->setTemperature(10.0); // Cold
    thermostat->update(); // Should trigger heating

    thermostat->setTemperature(35.0); // Hot
    thermostat->update(); // Should trigger cooling

    thermostat->setTemperature(20.0); // Comfortable
    thermostat->update(); // Should idle

    // Clean up
    //delete thermostat;
}


int main() {
   // testStates();
   // testCommand();
   // testIntegrator();
   testComposite();
   testObserver();
   testObserver2();
}