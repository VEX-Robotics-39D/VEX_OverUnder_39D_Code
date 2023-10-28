#include "main.h"

void Catapult::run_velocity(double velocity){
    catapultMotor.move_velocity(velocity*(0-600));
    catapultMotor2.move_velocity(velocity*(0-600));
}

void Catapult::brake(){
    catapultMotor.move_velocity(0);
    catapultMotor2.move_velocity(0);
}


Catapult catapult;