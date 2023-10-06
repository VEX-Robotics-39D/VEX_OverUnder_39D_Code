#pragma once
#include "main.h"

class Intake{
public:
    static void run(bool reverse=false);
    static void coast();

    //control code
    static void control();
};