#include "main.h"

void DriveTrain::pure_pursuit(double targetX,double targetY,double targetTheta){
    //get the current position of the robot
    double currentX=0;
    double currentY=0;
    double currentTheta=0;
    //calculate the distance from the robot to the target
    double distance=sqrt(pow(targetX-currentX,2)+pow(targetY-currentY,2));
    //calculate the angle from the robot to the target
    double angle=atan2(targetY-currentY,targetX-currentX);
    //calculate the angle from the robot to the target
    double angleDifference=angle-currentTheta;
    //calculate the turn velocity
    double turnVelocity=angleDifference*0.5;
    //calculate the forward velocity
    double forwardVelocity=distance*0.5;
    //move the drive train
}

void DriveTrain::control(){
    
    rightWheels.move_velocity(controller.get_analog(ANALOG_RIGHT_Y)*600);
    leftWheels.move_velocity(controller.get_analog(ANALOG_LEFT_Y)*600);
  
}