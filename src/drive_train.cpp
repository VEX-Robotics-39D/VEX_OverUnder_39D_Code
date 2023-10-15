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


const double DriveTrain::Control::AnglePID::kP=1;
const double DriveTrain::Control::AnglePID::kI=0.001;
const double DriveTrain::Control::AnglePID::kD=0.0;
double DriveTrain::Control::AnglePID::p=0.0;
double DriveTrain::Control::AnglePID::ii=0.0;
double DriveTrain::Control::AnglePID::d=0.0;
double DriveTrain::Control::AnglePID::error=0.0;
double DriveTrain::Control::AnglePID::lastError=0.0;
double DriveTrain::Control::AnglePID::target=0.0;

void DriveTrain::Control::AnglePID::set_target(double target){
    AnglePID::target=target;
}

void DriveTrain::Control::AnglePID::update(){
    error=target-Odometry::getTheta();
    pros::screen::print(pros::E_TEXT_MEDIUM,4,"Error: %f",error);
    p=error*kP;
    //ii*=0.95;
    //ii+=(error*kI);
    d=(error-lastError)*kD;
    lastError=error;
    pros::screen::print(pros::E_TEXT_MEDIUM,1,"P: %f",p);
    pros::screen::print(pros::E_TEXT_MEDIUM,2,"I: %f",ii);
    pros::screen::print(pros::E_TEXT_MEDIUM,3,"D: %f",d);
    DriveTrain::move_velocity(p+d,0-p-d);

}