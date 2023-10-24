#include "main.h"

void Autonomous::run(int time){
    pros::screen::print(pros::E_TEXT_MEDIUM ,0, "Autonomous running for %d ms", time);
    for(int i=1; i<=time/UPDATE_INTERVAL; i++){
        pros::delay(UPDATE_INTERVAL);
    }
}

