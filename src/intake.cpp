#include "main.h"

void Intake::run(int velocity){
	intakeMotor.move_velocity(velocity);
}

void Intake::coast(){
    intakeMotor.move_voltage(0);
}

bool Intake::lifted=true;

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
