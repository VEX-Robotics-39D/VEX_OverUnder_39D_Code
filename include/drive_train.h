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
            static const double kP;
            static const double kI;
            static const double kD;
            static double p;
            static double ii;
            static double d;
            static double error,lastError;
            static double target;
        public:
            static void set_target(double target);
            static void update();
        };
    };    
};