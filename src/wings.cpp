#include "main.h"

bool Wings::state=false;
bool Wings::xLastState=false;

void Wings::toggle(State s=State::Toggle){
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
	wingsPneumatic.set_value(state);
}

void Wings::control(){
    if(controller.get_digital(DIGITAL_X)){
		if(!xLastState){
			Wings::toggle(State::Toggle);
		}
		xLastState = true;
	}
	else{
		xLastState = false;
	}
}