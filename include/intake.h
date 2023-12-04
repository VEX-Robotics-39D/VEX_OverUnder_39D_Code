#pragma once
#include "main.h"

class Intake{
    static bool state;
public:
    static void run(int velocity);
    static void coast();
    static bool lifted;
    static void pneumatic_toggle(State s);
    //control code
};