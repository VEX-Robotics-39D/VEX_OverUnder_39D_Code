#include "main.h"

void Catapult::run_velocity(double velocity){
    catapultMotor.move_velocity(velocity*(0-600));
}

void Catapult::brake(){
    catapultMotor.move_velocity(0);
}

void Catapult::control(){
    if(controller.get_digital(DIGITAL_L1)){
		Catapult::run_velocity(1);
	}
	else{
	    Catapult::brake();
	}
	if(!PTO::extended){
	    if(controller.get_digital(DIGITAL_L1)){
		    leftWheel3.move_velocity(600);
			rightWheel3.move_velocity(600);
	    }
	    else{
	        Catapult::brake();
			leftWheel3.move_velocity(0);
			rightWheel3.move_velocity(0);
	    }
	}
}

Catapult catapult;