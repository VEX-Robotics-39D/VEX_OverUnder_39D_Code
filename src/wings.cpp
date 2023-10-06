#include "main.h"

bool Wings::state=false;

void Wings::toggle(){
    state=!state;
    leftWing.set_value(state);
    rightWing.set_value(state);
}