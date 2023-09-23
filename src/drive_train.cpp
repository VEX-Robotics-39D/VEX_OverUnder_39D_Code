#include "main.h"

void DriveTrain::move(double forwardVelocity,double turnVelocity){
    leftWheels.move_velocity(forwardVelocity*600-turnVelocity*300);
    rightWheels.move_velocity(forwardVelocity*600+turnVelocity*300);

}

DriveTrain driveTrain;