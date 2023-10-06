#pragma once
#include "main.h"

class DriveTrain{
public:
    
    //pid function
    static void pid(double target);
    //pure pursute function
    static void pure_pursuit(double targetX,double targetY,double targetTheta);

    //control code
    static void control();
};