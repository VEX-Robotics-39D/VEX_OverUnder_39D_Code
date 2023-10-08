#include "main.h"

bool Catapult::L1_Pressed;
bool Catapult::flung;

void Catapult::run_velocity(double velocity){
    catapultMotor.move_velocity(velocity*(0-600));
}

void Catapult::brake(){
    catapultMotor.move_velocity(0);
}

void Catapult::control(){	
    if(controller.get_digital(DIGITAL_L1)){
		flung=false;
		L1_Pressed = true;
	}
	if (flung&&catapultDistanceSensor.get() < 100){
		L1_Pressed = false;
	}
	if(catapultDistanceSensor.get() > 100){
		flung = true;
	}

	if(L1_Pressed){
		Catapult::run_velocity(1);
	}
	else{
		Catapult::brake();
	}
}

Catapult catapult;