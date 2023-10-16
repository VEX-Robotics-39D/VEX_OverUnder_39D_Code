#include "main.h"

void Intake::run(bool reverse){
    intakeMotor.move_voltage(reverse ? -12000 : 12000);
}

void Intake::coast(){
    intakeMotor.move_voltage(0);
}

bool Intake::lifted=true;

bool Intake::R1pressed=false;

void Intake::togglePneumatic(State s=State::Toggle){
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
		if(!R1pressed){
			Intake::togglePneumatic(State::Toggle);
			R1pressed=true;
		}
	}
	else{
		R1pressed=false;
	}
}