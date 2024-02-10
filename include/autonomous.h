#pragma once
#include "main.h"

class Autonomous{
public:
    class normalDrive{
        static void drive(double time);
        static void turn(double angle);
    };
    class Odometry{
        static double x;
        static double y;
        static double theta;
        static void setLoc(double x, double y, double theta);
        static double get_x();
        static double get_y();
        static double get_theta();
        static void updateLoc();
    };
    class PID{
        static double turnKP;
        static double turnKI;
        static double turnKD;
        static double driveKP;
        static double driveKI;
        static double driveKD;
        static double turnError;
        static double driveError;
        static double turnIntegral;
        static double driveIntegral;
        static double turnDerivative;
        static double driveDerivative;
        static double turnLastError;
        static double driveLastError;
        public:
        static void turnTo(double angle);
        static void driveTo(double x,double y);
        static void turnThenMoveTo(double x,double y);
        static void fastMoveTo(double x,double y);
    };
    class Routes{
        public:
        static void testpid();
        static void oppauton();
        static void skillsAuton();
        static void matchWinPointAuton();
        static void nearRushMid();
        static void sixTriball();
        static void farRushMid();
    };
};
