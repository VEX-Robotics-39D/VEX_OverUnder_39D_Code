#include "main.h"

void Flystick::run_velocity_spin(double velocity){
    flystickSpin.move_velocity(velocity);
}

void Flystick::brake_spin(){
    flystickSpin.move_velocity(0);
}

int Flystick::level=0;

void Flystick::update_state(){
    double error = flystickMovement.get_position()-level;
    flystickMovement.move_velocity(-error*0.1);
    pros::screen::print(pros::E_TEXT_MEDIUM, 0, "Flystick: %lf", flystickMovement.get_position());
}

Flystick catapult;