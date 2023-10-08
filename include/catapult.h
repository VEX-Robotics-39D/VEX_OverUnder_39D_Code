#pragma once
#include "main.h"

class Catapult{
public:
    static void run_velocity(double velocity);
    static void brake();
    static bool L1_Pressed;
    static bool flung;
    //control code
    static void control();
    static void setCataputReady();
};