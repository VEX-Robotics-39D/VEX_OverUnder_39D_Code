#include "main.h"

class Wings{
    static bool state;
    static bool xLastState;
public:
    static void toggle();

    //control code
    static void control();
};