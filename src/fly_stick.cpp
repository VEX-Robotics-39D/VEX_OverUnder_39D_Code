#include "main.h"

void Flystick::spin_volts(double volts){
    flyWheel.move_voltage(volts);
}

void Flystick::brake_spin(){
    flyWheel.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
    flyWheel.move_velocity(0);
}

int Flystick::level=0;

int Flystick::timeSinceLastChange=0;

void Flystick::update_state(){
    pros::screen::print(pros::E_TEXT_MEDIUM, 0, "Flystick: %lf", flystick.get_position());
    timeSinceLastChange++;
    if(timeSinceLastChange>150){
        flystick.set_brake_mode(pros::motor_brake_mode_e::E_MOTOR_BRAKE_HOLD);
        flystick.move_velocity(0);
        return;
    }
    double error = flystick.get_position()-level;
    flystick.move_velocity(-error*0.2);
    
}

Flystick catapult;