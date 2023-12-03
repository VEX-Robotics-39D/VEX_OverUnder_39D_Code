#pragma once
#include "globals.h"
#include "main.h"

class DriveTrain{
public:
    static void move_velocity(double left, double right);  
    static void stop();
};