#include "main.h"

void DriveTrain::move_velocity(double left, double right){
    leftWheels2.move_velocity(left);
    rightWheels2.move_velocity(right);
    if(PTO::extended){
        leftWheel3.move_velocity(left);
        rightWheel3.move_velocity(right);
    }
}


const double DriveTrain::Control::AnglePID::kP=1.25;
const double DriveTrain::Control::AnglePID::kI=0.0012;
const double DriveTrain::Control::AnglePID::kD=10;
const double DriveTrain::Control::AnglePID::toMultiply=0.95;
double DriveTrain::Control::AnglePID::p=0.0;
double DriveTrain::Control::AnglePID::Andrew=0.0;
double DriveTrain::Control::AnglePID::i=0.0;
double DriveTrain::Control::AnglePID::d=0.0;
double DriveTrain::Control::AnglePID::lastError=0.0;
double DriveTrain::Control::AnglePID::target=0.0;

void DriveTrain::Control::AnglePID::set_target(double target){
    AnglePID::target=target;
}

void DriveTrain::Control::AnglePID::update(){
    //Andrew = 0.0;
    double error=target-Odometry::getTheta();
    if (error == -std::numeric_limits<double>::infinity()) return;
    pros::screen::print(pros::E_TEXT_MEDIUM,4,"Error: %f",error);
    p=error*kP;
    i = i*toMultiply;
    i+=error*kI;
    d=(error-lastError)*kD;
    if((lastError<0&&error>0)||(lastError>0&&error<0)){
        i=0;
    }
    lastError=error;
    // pros::screen::print(pros::E_TEXT_SMALL,5,"kI: %f",kI);
    pros::screen::print(pros::E_TEXT_MEDIUM,1,"P: %f",p);
    pros::screen::print(pros::E_TEXT_MEDIUM,3,"D: %f",d);
    // pros::screen::print(pros::E_TEXT_MEDIUM,6,"error*kI: %f",(error*kI));
    pros::screen::print(pros::E_TEXT_MEDIUM,2,"I: %f",i);
    DriveTrain::move_velocity(p+i+d,0-p-i-d);
}