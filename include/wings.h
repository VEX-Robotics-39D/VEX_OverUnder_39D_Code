#include "main.h"

class Wings{
    static bool state;
    static bool xLastState;
public:
    static void set(State s=State::Toggle);

    //control code
    static void control();
};