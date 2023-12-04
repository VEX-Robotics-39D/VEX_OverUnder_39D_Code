#pragma once
#include "main.h"

class Flystick{
public:
    static int level;
    static int timeSinceLastChange;
    static void spin_volts(double volts);
    static void brake_spin();
    static void toggle_state();
    static void update_state();
};