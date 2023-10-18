#pragma once
#include "main.h"

class DriveTrain{
public:
    static void move_velocity(double left, double right);

    class Control{
    public:
        class AnglePID{
            static const double kP;
            static const double kI;
            static const double kD;
            static const double toMultiply;
            static double p;
            static double Andrew;
            static double i;
            static double d;
            static double lastError;
            static double target;
        public:
            static void set_target(double target);
            static void update();
        };
        class DistancePID{
            static const double kP;
            static const double kI;
            static const double kD;
            static double leftP;
            static double leftI;
            static double leftD;
            static double rightP;
            static double rightI;
            static double rightD;
            static double leftLastError;
            static double rightLastError;
            static double leftTarget;
            static double rightTarget;
        public:
            static void new_route();
            static void set_target(double target);
            static void update();
        };
    };    
};