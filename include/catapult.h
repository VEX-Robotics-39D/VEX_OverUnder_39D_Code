#pragma once
#include "main.h"

class Catapult{
public:
    static void run_velocity(double velocity);
    static void brake();

    //control code
    static void control();
};