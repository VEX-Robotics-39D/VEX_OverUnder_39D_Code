#include "main.h"



double Odometry::lastBackPosition = 0;
double Odometry::lastRightPosition = 0;
double Odometry::lastLeftPosition = 0;
double Odometry::lastTheta = 0;
double Odometry::x = 0;
double Odometry::y = 0;
double Odometry::theta = 0;

double Odometry::get_x(){
    return Odometry::x;
}

double Odometry::get_y(){
    return Odometry::y;
}

double Odometry::get_theta(){
    return Odometry::theta;
}


void Odometry::init(){
    lastBackPosition = backRotation.get_position();
    lastRightPosition = (rightWheel1.get_position() + rightWheel2.get_position()+rightWheel3.get_position())/3;
    lastLeftPosition = leftRotation.get_position();
    inertial.set_rotation(-theta);
    lastTheta = theta * PI/180.0;
}

void Odometry::set_x(double x){
    Odometry::x = x;
}

void Odometry::set_y(double y){
    Odometry::y = y;
}

void Odometry::set_theta(double theta){
    Odometry::theta = theta * PI/180.0;
    inertial.set_rotation(-theta);
}

double sinx_over_x(double x) {
return 1 - x * x / 6.0 + x * x * x * x / 120.0 - x * x * x * x * x * x / 5040.0 + x * x * x * x * x * x * x * x / 362880.0;
}

void Odometry::update(){

    double dl=(double) leftRotation.get_position()-lastLeftPosition;
    lastLeftPosition += dl;
    dl=dl*0.6/18000*PI*2.75/2;
    //double dr= (double) (rightWheel1.get_position()+rightWheel2.get_position()+rightWheel3.get_position())/3-lastRightPosition;
    //lastRightPosition += dr;
    //dr=dr*0.571428571428/180*PI*2;
    double db= (double) backRotation.get_position()-lastBackPosition;
    lastBackPosition += db;
    db=db*0.6/18000*PI*2.75/2;

    pros::screen::print(pros::E_TEXT_MEDIUM, 5, "dl: %f", dl);
    //pros::screen::print(pros::E_TEXT_MEDIUM, 6, "dr: %f", dr);
    pros::screen::print(pros::E_TEXT_MEDIUM, 7, "db: %f", db);

    double tempCurrRotation = 0-inertial.get_rotation();
    double drot = (tempCurrRotation-theta/PI*180);
    drot = drot*PI/180;
    double temp = sinx_over_x(drot / 2.0);
    double dyLoc = temp * dl;
    double dxLoc = temp * (db - drot * 2);

    pros::screen::print(pros::E_TEXT_MEDIUM, 8, "dyloc: %f", dyLoc);
    pros::screen::print(pros::E_TEXT_MEDIUM, 9, "dxloc: %f", dxLoc);

    double averot=theta+drot/2.0;

    double dx=0-dxLoc*sin(averot)+dyLoc*cos(averot);
    double dy=dxLoc*cos(averot)+dyLoc*sin(averot);

    x+=dx;
    y+=dy;
    theta+=drot;

}
