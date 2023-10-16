#pragma once
#include "main.h"

class Intake{
public:
    static void run(bool reverse=false);
    static void coast();
    static bool lifted;
    static bool R1pressed;
    //control code
    static void togglePneumatic(State s);
    static void control();
};