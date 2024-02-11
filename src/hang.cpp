#include "main.h"

void Hang::toggle(State s=State::Toggle){
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
	hangPneumatic.set_value(state);
}