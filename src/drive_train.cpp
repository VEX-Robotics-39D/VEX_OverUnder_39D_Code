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


const double DriveTrain::Control::AnglePID::kP=0.5;
const double DriveTrain::Control::AnglePID::kI=0.0;
const double DriveTrain::Control::AnglePID::kD=0.0;
double DriveTrain::Control::AnglePID::p=0.0;
double DriveTrain::Control::AnglePID::i=0.0;
double DriveTrain::Control::AnglePID::d=0.0;
double DriveTrain::Control::AnglePID::error=0.0;
double DriveTrain::Control::AnglePID::lastError=0.0;
double DriveTrain::Control::AnglePID::target=0.0;

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