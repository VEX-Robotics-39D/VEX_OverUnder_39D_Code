#pragma once
#include "main.h"

class Intake{
public:
    static void run(bool reverse=false);
    static void coast();
    static bool lifted;
    //control code
    static void setPneumatic(State s=State::Toggle);
    static void control();
};