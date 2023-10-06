#include "main.h"

bool Wings::state=false;
bool Wings::xLastState=false;

void Wings::toggle(){
    state=!state;
    leftWing.set_value(state);
    rightWing.set_value(state);
}

void Wings::control(){
    if(controller.get_digital(DIGITAL_X)){
			if(!xLastState){
				Wings::toggle();
			}
			xLastState = true;
		}
		else{
			xLastState = false;
		}
}