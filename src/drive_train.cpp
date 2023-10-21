#include "main.h"

void DriveTrain::move_velocity(double left, double right){
    leftWheels2.move_velocity(left);
    rightWheels2.move_velocity(right);
    if(PTO::extended){
        leftWheel3.move_velocity(left);
        rightWheel3.move_velocity(right);
    }
}

bool DriveTrain::Control::AnglePID::state = false;
const double DriveTrain::Control::AnglePID::kP=1.25;
const double DriveTrain::Control::AnglePID::kI=0.12*UPDATE_INTERVAL/1000.0;
const double DriveTrain::Control::AnglePID::kD=0.1/UPDATE_INTERVAL*1000.0;
const double DriveTrain::Control::AnglePID::toMultiply=0.95;
double DriveTrain::Control::AnglePID::p=0.0;
double DriveTrain::Control::AnglePID::Andrew=0.0;
double DriveTrain::Control::AnglePID::i=0.0;
double DriveTrain::Control::AnglePID::d=0.0;
double DriveTrain::Control::AnglePID::lastError=0.0;
double DriveTrain::Control::AnglePID::target=0.0;

void DriveTrain::Control::AnglePID::set_state(State s=State::Toggle){
                switch (s){
                    case State::On:
                        state=true;
                        break;
                    case State::Off:
                        state=false;
                        break;
                    case State::Toggle:
                        state=!state;
                        break;
                }
 }

void DriveTrain::Control::AnglePID::set_target(double target){
    AnglePID::target=target;
}

void DriveTrain::Control::AnglePID::update(){
    //Andrew = 0.0;
    if(state==false){
        return;
    }
    double error=target-Odometry::getTheta();
    if (error == -std::numeric_limits<double>::infinity()) return;
    //pros::screen::print(pros::E_TEXT_MEDIUM,4,"Error: %f",error);
    p=error*kP;
    i = i*toMultiply;
    i+=error*kI;
    d=(error-lastError)*kD;
    if((lastError<0&&error>0)||(lastError>0&&error<0)){
        i=0;
    }
    lastError=error;
    // pros::screen::print(pros::E_TEXT_SMALL,5,"kI: %f",kI);
    //pros::screen::print(pros::E_TEXT_MEDIUM,1,"P: %f",p);
    //pros::screen::print(pros::E_TEXT_MEDIUM,3,"D: %f",d);
    // pros::screen::print(pros::E_TEXT_MEDIUM,6,"error*kI: %f",(error*kI));
    //pros::screen::print(pros::E_TEXT_MEDIUM,2,"I: %f",i);
    DriveTrain::move_velocity(p+i+d,0-p-i-d);
}

bool DriveTrain::Control::DistancePID::state = false;
const double DriveTrain::Control::DistancePID::kP=0.175                                                                            ;
const double DriveTrain::Control::DistancePID::kI=0.077*UPDATE_INTERVAL/1000.0;
const double DriveTrain::Control::DistancePID::kD=0/UPDATE_INTERVAL*1000.0;
double DriveTrain::Control::DistancePID::leftP=0.0;
double DriveTrain::Control::DistancePID::leftI=0.0;
double DriveTrain::Control::DistancePID::leftD=0.0;
double DriveTrain::Control::DistancePID::rightP=0.0;
double DriveTrain::Control::DistancePID::rightI=0.0;
double DriveTrain::Control::DistancePID::rightD=0.0;
double DriveTrain::Control::DistancePID::leftLastError=0.0;
double DriveTrain::Control::DistancePID::rightLastError=0.0;
double DriveTrain::Control::DistancePID::leftTarget=0.0;
double DriveTrain::Control::DistancePID::rightTarget=0.0;

void DriveTrain::Control::DistancePID::set_state(State s=State::Toggle){
                switch (s){
                    case State::On:
                        state=true;
                        break;
                    case State::Off:
                        state=false;
                        break;
                    case State::Toggle:
                        state=!state;
                        break;
                }
 }

void DriveTrain::Control::DistancePID::new_route(){
    leftWheel1.tare_position();
    leftWheel2.tare_position();
    rightWheel1.tare_position();
    rightWheel2.tare_position();
}

void DriveTrain::Control::DistancePID::set_target(double target){
    DistancePID::leftTarget=target;
    DistancePID::rightTarget=target;
}

void DriveTrain::Control::DistancePID::update(){
    if(state==false){
        return;
    }
    double leftError=leftTarget-(leftWheel1.get_position()+leftWheel2.get_position())/2.0;
    double rightError=rightTarget-(rightWheel1.get_position()+rightWheel2.get_position())/2.0;
    pros::screen::print(pros::E_TEXT_MEDIUM,0,"Left Error: %f",leftError);
    pros::screen::print(pros::E_TEXT_MEDIUM,1,"Right Error: %f",rightError);
    //if (leftError == -std::numeric_limits<double>::infinity()||rightError == -std::numeric_limits<double>::infinity()) return;
    leftP=leftError*kP;
    leftI+=leftError*kI;
    leftD=(leftError-leftLastError)*kD;
    if((leftLastError<0&&leftError>0)||(leftLastError>0&&leftError<0)){
        leftI=0;
    }
    leftLastError=leftError;
    rightP=rightError*kP;
    rightI+=rightError*kI;
    rightD=(rightError-rightLastError)*kD;
    if((rightLastError<0&&rightError>0)||(rightLastError>0&&rightError<0)){
        rightI=0;
    }
    rightLastError=rightError;
    DriveTrain::move_velocity(leftP+leftI+leftD,rightP+rightI+rightD);

}
