#pragma once
#include "main.h"

class Flystick{
public:
    static void run_velocity_spin(double velocity);
    static void run_velocity_movement(double velocity);
    static void brake_spin();
    static void brake_movement();
};