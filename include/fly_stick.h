#pragma once
#include "main.h"

class Flystick{
public:
static int level;
    static void run_velocity_spin(double velocity);
    static void brake_spin();
    static void toggle_state();
    static void update_state();
};