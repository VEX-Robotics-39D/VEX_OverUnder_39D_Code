#include "main.h"
#include <cmath>

double Odometry::x = 0;
double Odometry::y = 0;
double Odometry::theta = 0;

double Odometry::getX(){
    return x;
}

double Odometry::getY(){
    return y;
}

double Odometry::getTheta(){
    return theta;
}

void Odometry::updateOdom(){
    double deltaOdometryWheelPosition = odometryWheel.get_position() - odometryWheelPosition;
    double deltaLeftWheelPosition = (leftWheel1.get_position()+leftWheel2.get_position()+leftWheel3.get_position())/3.0 - leftWheelPosition;
    double deltaRightWheelPosition = (rightWheel1.get_position()+rightWheel2.get_position()+rightWheel3.get_position())/3.0 - rightWheelPosition;
    
    double deltaTheta = (deltaRightWheelPosition - deltaLeftWheelPosition) / (2*leftRightWheelDistance);
    
    double leftWheelTurnRadius = deltaLeftWheelPosition / deltaTheta;
    double odometryWheelTurnRadius = deltaOdometryWheelPosition / deltaTheta;

    double deltaX = (deltaLeftWheelPosition + leftRightWheelDistance) * (cos(deltaTheta) - 1)
        + (odometryWheelTurnRadius - odometryWheelDistance) * (0 - sin(deltaTheta));
    double deltaY = (deltaLeftWheelPosition + leftRightWheelDistance) * sin(deltaTheta) 
        + (odometryWheelTurnRadius - odometryWheelDistance) * (cos(deltaTheta) - 1);

    theta += deltaTheta;
    x += deltaX;
    y += deltaY;

    leftWheelPosition += deltaLeftWheelPosition;
    rightWheelPosition += deltaRightWheelPosition;
    odometryWheelPosition += deltaOdometryWheelPosition;
}

void Odometry::updateInertial(){
    theta = inertial.get_rotation();
}