#pragma once
#include "main.h"

class Autonomous{
public:
    class normalDrive{
        static void drive(double time);
        static void turn(double angle);
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

        static double turnSatisfactoryTime;
        static double driveSatisfactoryTime;
        static double fastMoveSatisfactoryTime;
        public:
        static void turnTo(double angle,double error);
        static void turnTo(double x,double y,double error);
        static void driveTo(double x,double y,double error);
        static void turnThenMoveTo(double x,double y, bool opposite);
        static void fastMoveTo(double x,double y,double stopRadius);
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
