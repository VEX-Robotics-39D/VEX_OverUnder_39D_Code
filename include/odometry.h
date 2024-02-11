#pragma once
#include "main.h"

class Odometry{
    public:
    void update();
    static double get_x();
    static double get_y();
    static double get_theta();
};
