#pragma once
#include "main.h"

class Odometry{
    private:
    static double lastBackPosition;
    static double lastRightPosition;
    static double lastLeftPosition;
    static double lastTheta;
    public:
    static double x;
    static double y;
    static double theta;

    static void init();
    static void update();
    static double get_x();
    static double get_y();
    static double get_theta();
    static void set_x(double x);
    static void set_y(double y);
    static void set_theta(double theta);
};
