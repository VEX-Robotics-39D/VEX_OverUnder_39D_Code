#pragma once
#include "main.h"

class Autonomous{
public:
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
        static void driveTo(double distance);
    };
    class Routes{
        public:
        static void testpid();
        static void oppauton();
        static void skillauton();
    };
};
