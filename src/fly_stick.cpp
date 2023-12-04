#include "main.h"

void Flystick::spin_volts(double volts){
    flystickSpin.move_voltage(volts);
}

void Flystick::brake_spin(){
    flystickSpin.move_velocity(0);
}

int Flystick::level=0;

int Flystick::timeSinceLastChange=0;

void Flystick::update_state(){
    pros::screen::print(pros::E_TEXT_MEDIUM, 0, "Flystick: %lf", flystickMovement.get_position());
    timeSinceLastChange++;
    if(timeSinceLastChange>150){
        flystickMovement.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
        flystickMovement.move_velocity(0);
        return;
    }
    double error = flystickMovement.get_position()-level;
    flystickMovement.move_velocity(-error*0.2);
    
}

Flystick catapult;