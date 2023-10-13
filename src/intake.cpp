#include "main.h"

void Intake::run(bool reverse){
    intakeMotor.move_voltage(reverse ? -12000 : 12000);
}

void Intake::coast(){
    intakeMotor.move_voltage(0);
}

void Intake::setPneumatic(State s=State::Toggle){
	switch(s){
		case State::Toggle:
			lifted=!lifted;
			break;
		case State::On:
			lifted=true;
			break;
		case State::Off:
			lifted=false;
			break;
	}
	intakePneumatic.set_value(lifted);
}

void Intake::control(){
    if(controller.get_digital(DIGITAL_L2)){
		Intake::run(true);
	}
	else if(controller.get_digital(DIGITAL_R2)){
		Intake::run();
	}
	else{
		Intake::coast();
	}

	if(controller.get_digital(DIGITAL_R1)){
		Intake::setPneumatic(State::Toggle);
	}
}