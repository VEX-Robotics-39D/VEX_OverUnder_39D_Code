#include "main.h"

void Intake::run(int velocity){
	intakeMotor.move_velocity(velocity);
}

void Intake::coast(){
    intakeMotor.move_voltage(0);
}

bool Intake::lifted=true;
