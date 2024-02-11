#include "main.h"

double Odometry::get_x(){
    return chassis.getPose().x;
}

double Odometry::get_y(){
    return chassis.getPose().y;
}

double Odometry::get_theta(){
    return (-chassis.getPose().theta);
}

double Odometry::lastBackPosition = 0;
double Odometry::lastRightPosition = 0;
double Odometry::lastLeftPosition = 0;
double Odometry::lastTheta = 0;
double Odometry::x = 0;
double Odometry::y = 0;
double Odometry::theta = 0;

void Odometry::init(){
    lastBackPosition = backRotation.get_position();
    lastRightPosition = 
    lastTheta = inertial.get_rotation();
    x=0;
    y=0;
    theta = 0;
}

double sinx_over_x(double x) {
return 1 - x * x / 6.0 + x * x * x * x / 120.0 -
        x * x * x * x * x * x / 5040.0;
}

void Odometry::update(){

    double dl=(double) leftOdometryWheel.get_position()-lastLeftPosition;
    dl=dl*0.6/18000*PI*2.75;
    double dr= (double) rightOdometryWheel.get_position()-lastRightPosition;
    dr=dr*0.6/18000*PI*2.75;
    double db= (double) backRotation.get_position()-lastBackPosition;
    db=db*0.6/18000*PI*2.75;


    double drot = (dr - dl) / (TRACK_WIDTH);
    double temp = sinx_over_x(drot / 2.0);
    double dyLoc = temp * (dl + dr) / 2.0;
    double dxLoc = temp * (db + drot * bRad);

    double averot=theta+drot/2.0;

    double dx=dxLoc*cos(averot)-dyLoc*sin(averot);
    double dy=dxLoc*sin(averot)+dyLoc*cos(averot);

    x+=dx;
    y+=dy;
    theta+=drot;

}
