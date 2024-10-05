#include "SmartDevice.h"
#include "Light.h"
#include "Door.h"
#include "Device.h"
#include "Thermostat.h"
#include "ThermoCool.h"
#include "ThermoHot.h"
#include "ThermoIdle.h"
#include "ThermostatState.h"
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

using namespace std;

// DEMO MAIN STUFF
#include <iostream>
#include <iomanip> // for std::setw
#include <chrono>
#include <thread>

// Color codes
#define RESET "\033[0m"
#define UNDERLINE "\033[4m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

void printHeader(const std::string &title)
{
    // std::cout << BOLD << CYAN << std::setw(50) << std::setfill('=') << "\n" << RESET;
    std::cout << BOLD << BLUE << std::setw(25) << title << RESET << "\n";
    // std::cout << BOLD << CYAN << std::setw(50) << std::setfill('=') << "\n" << RESET;
}
void typewriterEffect(const string &text, int delay)
{
    for (const char &c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
}

int main() {
// cout
//      << RESET << endl;
//     typewriterEffect(GREEN BOLD "╔═══════════════════════════════════════════════════════════════════════╗\n", 30);

//     // Middle text
//     typewriterEffect("║                      Welcome to LEBO_DREY'S SMART HOME...             ║\n", 30);

//     // Bottom border
//     typewriterEffect("╚═══════════════════════════════════════════════════════════════════════╝\n", 30);

//     typewriterEffect(YELLOW BOLD "Let's check our cool home system, shall we..??", 30);
//     cout << endl
//          << endl;
//     typewriterEffect(YELLOW BOLD "Loading....", 50);

//     cout << RESET << endl
//          << endl;

//     typewriterEffect(YELLOW BOLD "\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF", 50);

//     cout << RESET << endl
//          << endl;

    cout << endl
         << endl;

    // ==================Testing States==================
     typewriterEffect(MAGENTA BOLD "================== OUTPUTTING STATES ==================", 30);
     cout << RESET << endl << endl ;

    //std::cout << "==================Testing States==================\n";
    // Testing Light States
    std::cout << CYAN << "##############...LETS SEE THE LIGHTS...##############\n" << RESET <<endl;
    Light* myLight = new Light();
    myLight->display();

    cout << UNDERLINE<< "---------- Switch lights on ----------" << RESET << endl << endl;
    myLight->toggle();
    myLight->display();
    cout << endl;
    cout << UNDERLINE<< "---------- Switch lights off ----------" << RESET << endl << endl;
    myLight->toggle();
    myLight->display();
    cout << endl;

    // Testing Door States
    std::cout << CYAN << "##############...LETS SEE THE DOORS...##############\n" << RESET <<endl;
    Door* myDoor = new Door();
    myDoor->display();
    cout << endl;
    cout << UNDERLINE<< "---------- Lock doors ----------" << RESET << endl << endl;
    myDoor->lock();
    myDoor->display();
    cout << endl;
    cout << UNDERLINE<< "---------- Unlock doors ----------" << RESET << endl << endl;
    myDoor->unlock();
    myDoor->display();
    cout << endl;

    // Testing Thermostat States
    std::cout << CYAN << "##############...LETS SEE THE THERMOSTAT...##############\n" << RESET <<endl;
    Thermostat* myThermo = new Thermostat();
    myThermo->display();

    cout << endl;
    cout << UNDERLINE<< "---------- Cool the thermostat ----------" << RESET << endl << endl;

    myThermo->cool();
    myThermo->display();

    cout << endl;
    cout << UNDERLINE<< "---------- Heat up the thermostat ----------" << RESET << endl << endl;


    myThermo->heat();

    cout << endl;
    cout << UNDERLINE<< "---------- Set thermostat temp to 35 ----------" << RESET << endl << endl;

    myThermo->setTemperature(35);
    myThermo->display();

     cout << endl;
    cout << UNDERLINE<< "---------- Set thermostat temp to 15 ----------" << RESET << endl << endl;

    myThermo->setTemperature(15);
    myThermo->display();

    cout << endl;
    cout << UNDERLINE<< "---------- Idle the thermostat ----------" << RESET << endl << endl;

    myThermo->idle();

    delete myDoor;
    delete myLight;
    delete myThermo;

    // ==================Testing Command==================
    cout << endl;
    typewriterEffect(MAGENTA BOLD "================== SMART HOME COMMANDS ==================", 30);
     cout << RESET << endl << endl ;

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

    UnlockDoors* unlockDoorsCmd = new UnlockDoors();
    unlockDoorsCmd->addDoor(frontDoor);
    unlockDoorsCmd->addDoor(backDoor);

    AllLightsOn* lightsOn = new AllLightsOn();
    lightsOn->addLights(livingRoomLight);
    lightsOn->addLights(kitchenLight);

    AllLightsOff* lightsOff = new AllLightsOff();
    lightsOff->addLights(livingRoomLight);
    lightsOff->addLights(kitchenLight);

     typewriterEffect(MAGENTA BOLD "================== WELCOME BACK HOME ROUTINE ==================", 30);
     cout << RESET << endl << endl ;
    MacroRoutine* goodeveningRoutine = new MacroRoutine("Welcome Back");

    goodeveningRoutine->addCommand(lightsOn);

     cout << endl;
    cout << UNDERLINE<< GREEN<<"---------- ROUTINE UNLOCKS ALL DOORS ----------" << RESET << endl << endl;

    goodeveningRoutine->addCommand(unlockDoorsCmd);
    goodeveningRoutine->execute();

    cout << endl;
    cout << UNDERLINE<< GREEN<<"---------- ROUTINE LOCKS ALL DOORS ----------" << RESET << endl << endl;
    lockDoorsCmd->execute();
     cout << endl;


     typewriterEffect(MAGENTA BOLD "================== GOODNIGHT MACROROUTINE ==================", 30);
     cout << RESET << endl << endl ;

    MacroRoutine* goodnightRoutine = new MacroRoutine("GoodNight");
    goodnightRoutine->addCommand(lightsOff);
    goodnightRoutine->addCommand(lockDoorsCmd);

    cout << endl;
    cout << UNDERLINE<< GREEN<<  "---------- EXECUTING GOODNIGHT ROUTINE ----------" << RESET << endl << endl;

    goodnightRoutine->execute();


    std::cout << BOLD << UNDERLINE << GREEN <<"\nExecuting Unlock Doors Command...\n" << RESET << endl;
    unlockDoorsCmd->execute();

    std::cout << BOLD << UNDERLINE << GREEN <<"\nExecuting Toggle Lights Command...\n" << RESET << endl;
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

    cout << endl;

    // ==================Testing Integrator==================
    typewriterEffect(MAGENTA BOLD "================== LET US INTEGRATE OUR THERMOSTAT TO OUR SMART HOME ==================", 30);
     cout << RESET << endl << endl ;
    LegacyThermostat* legacyThermostat = new LegacyThermostat();
    ThermoIntegrator* smartThermostat = new ThermoIntegrator(legacyThermostat);

    smartThermostat->display();
    cout << YELLOW << BOLD<< endl <<" ***** set temperature to 25 ***** "  << RESET << endl; 

    smartThermostat->setTemperature(25);
    smartThermostat->display();

    cout << YELLOW << BOLD << endl <<" ***** set to cool ***** "  << RESET << endl;
    smartThermostat->cool();
    smartThermostat->display();

    cout << YELLOW << BOLD<< endl << " ***** set to heat ***** "  << RESET << endl;
    smartThermostat->heat();
    smartThermostat->display();

    cout << YELLOW << BOLD<< endl <<" ***** idle the thermostat ***** "  << RESET << endl;
    smartThermostat->idle();
    smartThermostat->display();

    cout << YELLOW << BOLD << endl << " ***** set to heat ***** "  << RESET << endl;
    smartThermostat->heat();
    smartThermostat->display();

    delete smartThermostat;
    delete legacyThermostat;

    // ==================Testing Composite==================
     typewriterEffect(MAGENTA BOLD "================== LETS SEE HOW THE SMART DEVICES ARE ARRANGED IN EACH ROOM IN OUR HOME ==================", 30);
     cout << RESET << endl << endl ;    
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

    std::cout << UNDERLINE << RED << BOLD << "===== DISPLAYING HOME SECTION =====" << RESET << std::endl << endl;
    livingArea->display();
    std::cout << UNDERLINE << RED << BOLD <<"\n===== TURNING ON ALL LIGHTS =====" << RESET << std::endl  << endl;
    livingArea->turnOn();
    livingArea->display();
    std::cout << UNDERLINE << RED << BOLD <<"\n===== TURNING OFF ALL LIGHTS =====" << RESET << std::endl << endl;
    livingArea->turnOff();
    livingArea->display();
    std::cout << UNDERLINE << RED << BOLD <<"\n===== LOCKING ALL DOORS =====" << RESET << std::endl << endl;
    livingArea->lock();
    livingArea->display();
    std::cout << UNDERLINE << RED << BOLD << "\n===== UNLOCKING ALL DOORS =====" << RESET << std::endl << endl;
    livingArea->unlock();
    livingArea->display();

    delete livingArea;
    delete livingRoom;
    delete bedroom;
    delete light1;
    delete light2;
    delete door1;
    delete door2;

    cout << endl << endl;

    // ==================Testing Observer==================
     typewriterEffect(MAGENTA BOLD "================== OBSERVING THE SENSORS IN OUR SMART HOME ==================", 30);
     cout << RESET << endl << endl ;    
     HeatSensor* heatSensor = new HeatSensor();
    MotionSensor* motionSensor = new MotionSensor();

    Thermostat* thermostat = new Thermostat();
    Door* door = new Door();

    heatSensor->addDevice(thermostat);
    motionSensor->addDevice(door);

    std::cout << "\n===== Heat Sensor Detects a Temperature Change =====" << std::endl;
    thermostat->setTemperature(35.0);
    heatSensor->detectChange();
    std::cout << "\n===== Motion Sensor Detects Motion =====" << std::endl;
    motionSensor->detectChange();
    std::cout << "\n===== Heat Sensor Detects Another Temperature Change =====" << std::endl;
    thermostat->setTemperature(15.0);
    heatSensor->detectChange();
    std::cout << "\n===== Motion Detected Near the Door =====" << std::endl;
    motionSensor->detectChange();

    delete heatSensor;
    delete motionSensor;
    delete thermostat;
    delete door;

    return 0;
}
