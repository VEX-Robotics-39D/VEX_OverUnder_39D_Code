#include "main.h"

void Catapult::coast(){
    catapultMotor.move_voltage(0);
}

Catapult catapult;