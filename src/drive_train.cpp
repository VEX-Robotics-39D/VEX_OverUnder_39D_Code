#include "main.h"

void DriveTrain::move_velocity(double left, double right){
    leftWheels2.move_velocity(left);
    rightWheels2.move_velocity(right);
    if(PTO::extended){
        leftWheel3.move_velocity(left);
        rightWheel3.move_velocity(right);
    }
}

void DriveTrain::control(){
    move_velocity(Utilities::drive_control_map(controller.get_analog(ANALOG_LEFT_Y))*600.0,Utilities::drive_control_map(controller.get_analog(ANALOG_RIGHT_Y))*600.0);
}

void DriveTrain::Control::AnglePID::set_target(double target){
    AnglePID::target=target;
}

void DriveTrain::Control::AnglePID::update(){
    error=target-Odometry::getTheta();
    p=error*kP;
    i*=0.95;
    i+=error*kI;
    d=(error-lastError)*kD;
    lastError=error;
    DriveTrain::move_velocity(0-p-i-d,p+i+d);

}