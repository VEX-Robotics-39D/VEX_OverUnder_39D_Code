#include "main.h"

void Intake::run(int velocity){
	intakeMotor.move_velocity(velocity);
}

void Intake::coast(){
    intakeMotor.move_voltage(0);
}

bool Intake::state=false;
void Intake::pneumatic_toggle(State s){
    switch(s){
		case State::Toggle:
			state=!state;
			break;
		case State::On:
			state=true;
			break;
		case State::Off:
			state=false;
			break;
	}
	intakePneumatic.set_value(state);
}
bool Intake::lifted=true;
