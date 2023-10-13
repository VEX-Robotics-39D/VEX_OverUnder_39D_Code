#pragma once
#include "main.h"

class DriveTrain{
public:
    static void move_velocity(double left, double right);

    //control code
    static void control();

    class Control{
    public:
        class AnglePID{
            static const double kP=0.5;
            static const double kI=0;
            static const double kD=0;
            static double p,i,d;
            static double error,lastError;
            static double target;
        public:
            static void set_target(double target);
            static void update();
        };
    };    
};