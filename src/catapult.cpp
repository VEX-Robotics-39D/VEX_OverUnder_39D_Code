#include "main.h"

void Catapult::run_velocity(double velocity){
    catapultMotor1.move_velocity(velocity);
    catapultMotor2.move_velocity(velocity);
    
}

void Catapult::brake(){
    catapultMotor1.move_velocity(0);
    catapultMotor2.move_velocity(0);
}

Catapult catapult;