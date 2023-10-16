#include "main.h"

class Wings{
    static bool state;
    static bool xLastState;
public:
    static void toggle(State s);

    //control code
    static void control();
};