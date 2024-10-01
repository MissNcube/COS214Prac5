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
#include <iostream>
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

int main()
{
    
    cout << endl
         << endl
         << RESET << endl;
    typewriterEffect(GREEN BOLD "╔═══════════════════════════════════════════════════════════════════════╗\n", 30);

    // Middle text
    typewriterEffect("║                      Welcome to LEBO_DREY'S SMART HOME...          ║\n", 30);

    // Bottom border
    typewriterEffect("╚═══════════════════════════════════════════════════════════════════════╝\n", 30);

    typewriterEffect(YELLOW BOLD "Let's check our cool home system, shall we..??", 30);
    cout << endl
         << endl;
    typewriterEffect(YELLOW BOLD "Loading....", 50);

    cout << RESET << endl
         << endl;

    typewriterEffect(YELLOW BOLD "\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF\u25CF", 50);

    cout << RESET << endl
         << endl;

    cout << endl
         << endl;

    return 0;
}