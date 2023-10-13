#include "main.h"

class PTO{
public:
    static bool extended;
    static void set(State s=State::Toggle);
    static void control();
};