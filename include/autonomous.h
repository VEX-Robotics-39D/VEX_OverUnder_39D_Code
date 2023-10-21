#pragma once
#include "main.h"

class Autonomous{
public:
    static void run(int time);
    class Routines{
    public:
        static void common_1_0();
        static void test_angle_PID();
        static void test_distance_PID();

        static void match_op();
    };
};
