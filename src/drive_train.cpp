#include "main.h"

void DriveTrain::move_velocity(double left, double right){
    leftWheels.move_velocity(left);
    rightWheels.move_velocity(right);
}
void DriveTrain::stop(){
    leftWheels.move_velocity(0);
    rightWheels.move_velocity(0);
    leftWheels.move_relative(0,600);
    rightWheels.move_relative(0,600);          
}
