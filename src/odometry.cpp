#include "main.h"

double Odometry::get_x(){
    return chassis.getPose().x;
}

double Odometry::get_y(){
    return chassis.getPose().y;
}

double Odometry::get_theta(){
    return 90-chassis.getPose().theta;
}


