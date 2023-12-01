#include "main.h"

void Flystick::run_velocity_spin(double velocity){
    flystickSpin.move_velocity(velocity);
}

void Flystick::brake_spin(){
    flystickSpin.move_velocity(0);
}

int Flystick::level=0;

void Flystick::update_state(){
    int error = flystickSpin.get_position()-level;
    flystickSpin.move_velocity(-error*0.1);
    
}

Flystick catapult;