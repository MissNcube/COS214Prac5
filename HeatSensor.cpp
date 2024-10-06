#include "HeatSensor.h"

HeatSensor::HeatSensor()
{
}

HeatSensor::~HeatSensor()
{
}

/**
 * @brief Detects a heat change and notifies all connected devices.
 * 
 * This method simulates the detection of a change in heat, triggering a notification to all devices
 * that are connected to the heat sensor. Upon detecting a change, it outputs a message indicating
 * heat detection and calls the notifyDevices() method to alert the connected devices.
 * 
 * @see Sensor::notifyDevices()
 */

void HeatSensor::detectChange()
{
    cout << "Heat detected! Notifying all connected devices" << endl;
    notifyDevices();
}
