#include "main.h"

void Flystick::run_velocity_movement(double velocity){
    flystickMovement.move_velocity(velocity);   
}

void Flystick::brake_movement(){
    flystickMovement.move_velocity(0);
}

void Flystick::run_velocity_spin(double velocity){
    flystickSpin.move_velocity(velocity);
}

void Flystick::brake_spin(){
    flystickSpin.move_velocity(0);
}


Flystick catapult;