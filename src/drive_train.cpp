#include "main.h"

void DriveTrain::move_velocity(double forwardVelocity,double turnVelocity){
    leftWheels.move_velocity(forwardVelocity*600-turnVelocity*300);
    rightWheels.move_velocity(forwardVelocity*600+turnVelocity*300);
}

void DriveTrain::move_voltage(double leftVoltage,double rightVoltage){
    leftWheels.move_voltage(leftVoltage);
    rightWheels.move_voltage(rightVoltage);
}

DriveTrain driveTrain;