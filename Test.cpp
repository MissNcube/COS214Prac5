#include "doctest.h"

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

TEST_CASE("Testing Light States") {
    Light* myLight = new Light();
    CHECK(myLight != nullptr);

    // Initial state should be off
    CHECK_EQ(myLight->getStatus(), "Off");
    myLight->toggle();
    CHECK_EQ(myLight->getStatus(), "On");
    myLight->toggle();
    CHECK_EQ(myLight->getStatus(), "Off");

    delete myLight;
}

TEST_CASE("Testing Door States") {
    Door* myDoor = new Door();
    CHECK(myDoor != nullptr);

    // Initial state should be unlocked
    CHECK_EQ(myDoor->getStatus(), "Unlocked");
    myDoor->lock();
    CHECK_EQ(myDoor->getStatus(), "Locked");
    myDoor->unlock();
    CHECK_EQ(myDoor->getStatus(), "Unlocked");

    delete myDoor;
}

TEST_CASE("Testing Thermostat States") {
    Thermostat* myThermo = new Thermostat();
    CHECK(myThermo != nullptr);

    // Initial state should be idle and default temperature
    CHECK_EQ(myThermo->getTemperature(), 20.0); // Assuming default is 20
    myThermo->cool();
    CHECK_EQ(myThermo->getStatus(), "Cool");
    myThermo->heat();
    CHECK_EQ(myThermo->getStatus(), "Hpt");

    myThermo->setTemperature(35);
    CHECK_EQ(myThermo->getTemperature(), 35);

    myThermo->setTemperature(15);
    CHECK_EQ(myThermo->getTemperature(), 15);

    myThermo->idle();
    CHECK_EQ(myThermo->getStatus(), "Idle");

    delete myThermo;
}

TEST_CASE("Testing Command Patterns") {
    Light* livingRoomLight = new Light();
    Light* kitchenLight = new Light();
    Door* frontDoor = new Door();
    Door* backDoor = new Door();

    ToggleAllLights* toggleLightsCmd = new ToggleAllLights();
    toggleLightsCmd->addLights(livingRoomLight);
    toggleLightsCmd->addLights(kitchenLight);

    LockDown* lockDoorsCmd = new LockDown();
    lockDoorsCmd->addDoor(frontDoor);
    lockDoorsCmd->addDoor(backDoor);

    // Initially both lights should be off
    CHECK_EQ(livingRoomLight->getStatus(), "Off");
    CHECK_EQ(kitchenLight->getStatus(), "Off");

    // Execute command
    toggleLightsCmd->execute();
    CHECK_EQ(livingRoomLight->getStatus(), "On");
    CHECK_EQ(kitchenLight->getStatus(), "On");

    // Lock both doors
    lockDoorsCmd->execute();
    CHECK_EQ(frontDoor->getStatus(), "Locked");
    CHECK_EQ(backDoor->getStatus(), "Locked");

    // Clean up
    delete livingRoomLight;
    delete kitchenLight;
    delete frontDoor;
    delete backDoor;
    delete toggleLightsCmd;
    delete lockDoorsCmd;
}

TEST_CASE("Testing Integrator") {
    LegacyThermostat* legacyThermostat = new LegacyThermostat();
    ThermoIntegrator* smartThermostat = new ThermoIntegrator(legacyThermostat);

    smartThermostat->setTemperature(25);
    CHECK_EQ(smartThermostat->getTemperature(), 25);

    smartThermostat->cool();
    CHECK_EQ(smartThermostat->getStatus(), "Cool");

    smartThermostat->heat();
    CHECK_EQ(smartThermostat->getStatus(), "Hot");

    delete smartThermostat;
    delete legacyThermostat;
}

TEST_CASE("Testing Composite Pattern") {
    HomeSection* livingArea = new HomeSection("Living Area");
    Room* livingRoom = new Room("Living Room");
    Room* bedroom = new Room("Bedroom");

    livingArea->addRoom(livingRoom);
    livingArea->addRoom(bedroom);

    SmartDevice* light1 = new Light();
    SmartDevice* light2 = new Light();
    SmartDevice* door1 = new Door();
    SmartDevice* door2 = new Door();

    livingRoom->addDevice(light1);
    livingRoom->addDevice(door1);
    bedroom->addDevice(light2);
    bedroom->addDevice(door2);

    // Test turning on all lights
    livingArea->turnOn();
    CHECK_EQ(light1->getStatus(), "On");
    CHECK_EQ(light2->getStatus(), "On");

    // Test locking all doors
    livingArea->lock();
    CHECK_EQ(door1->getStatus(), "Locked");
    CHECK_EQ(door2->getStatus(), "Locked");

    delete livingArea;
    delete livingRoom;
    delete bedroom;
    delete light1;
    delete light2;
    delete door1;
    delete door2;
}

TEST_CASE("Testing Observer Pattern") {
    HeatSensor* heatSensor = new HeatSensor();
    MotionSensor* motionSensor = new MotionSensor();
    Thermostat* thermostat = new Thermostat();
    Door* door = new Door();

    heatSensor->addDevice(thermostat);
    motionSensor->addDevice(door);

    // Simulate temperature change
    thermostat->setTemperature(35.0);  // High temperature
    heatSensor->detectChange();
    CHECK_EQ(thermostat->getStatus(), "Cool");

    // Simulate motion near the door
    motionSensor->detectChange();
    CHECK_EQ(door->getStatus(), "Locked");

    delete heatSensor;
    delete motionSensor;
    delete thermostat;
    delete door;
}



