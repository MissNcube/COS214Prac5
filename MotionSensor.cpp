#include "MotionSensor.h"

MotionSensor::MotionSensor()
{
}

MotionSensor::~MotionSensor()
{
}

/**
 * @brief Detects a change in motion and notifies all connected devices.
 * 
 * This method simulates the detection of a change in motion, triggering a notification to all devices
 * that are connected to the motion sensor. Upon detecting a change, it outputs a message indicating
 * motion detection and calls the notifyDevices() method to alert the connected devices.
 * 
 * @see Sensor::notifyDevices()
 */
void MotionSensor::detectChange()
{
    cout << "Motion detected! Notifying all connected devices" << endl;
    notifyDevices();
}
