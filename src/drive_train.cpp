#include "main.h"

void DriveTrain::move_velocity(double left, double right){
    leftWheels.move_velocity(left);
    rightWheels.move_velocity(right);
}
void DriveTrain::stopLeft(){
    leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    leftWheels.move_velocity(0);
    leftWheels.brake();
}
void DriveTrain::stopRight(){
    rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    rightWheels.move_velocity(0);
    rightWheels.brake();
}
