#include "main.h"

void DriveTrain::move_velocity(double left, double right){
    leftWheels.move_velocity(left);
    rightWheels.move_velocity(right);
}
