#include "main.h"

void Intake::run(bool reverse){
    intakeMotor.move_voltage(reverse ? -12000 : 12000);
}

void Intake::coast(){
    intakeMotor.move_voltage(0);
}