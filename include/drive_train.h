#pragma once
#include "main.h"

class DriveTrain{
public:
    //move the drive train at a given velocity maintained by pros built in PID
    static void move_velocity(double forwardVelocity,double turnVelocity);
    //move the drive train at a given voltage
    static void move_voltage(double leftVoltage,double rightVoltage);
    
};