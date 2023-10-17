#include "main.h"

bool Wings::state=false;

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