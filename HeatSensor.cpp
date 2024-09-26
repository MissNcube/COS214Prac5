#include "HeatSensor.h"

HeatSensor::HeatSensor()
{
}

HeatSensor::~HeatSensor()
{
}

void HeatSensor::detectChange()
{
    cout << "Heat detected! Notifying all connected devices" << endl;
    notifyDevices();
}
