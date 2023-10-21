#include "main.h"

bool DriveControl::ControllerStates::L1_last_state = false;
bool DriveControl::ControllerStates::R1_last_state = false;
bool DriveControl::ControllerStates::L2_last_state = false;
bool DriveControl::ControllerStates::R2_last_state = false;
bool DriveControl::ControllerStates::up_last_state = false;
bool DriveControl::ControllerStates::down_last_state = false;
bool DriveControl::ControllerStates::left_last_state = false;
bool DriveControl::ControllerStates::right_last_state = false;
bool DriveControl::ControllerStates::X_last_state = false;
bool DriveControl::ControllerStates::Y_last_state = false;
bool DriveControl::ControllerStates::A_last_state = false;
bool DriveControl::ControllerStates::B_last_state = false;

bool DriveControl::catapultFlung=false;
bool DriveControl::catapultMoving=true;

bool DriveControl::ControllerStates::is_activated(pros::controller_digital_e_t button){
    switch(button){
        case DIGITAL_L1:{
            bool temp = L1_last_state;
            L1_last_state = controller.get_digital(DIGITAL_L1);
            return L1_last_state && !temp;
        }
        case DIGITAL_R1:{
            bool temp = R1_last_state;
            R1_last_state = controller.get_digital(DIGITAL_R1);
            return R1_last_state && !temp;
        }
        case DIGITAL_L2:{
            bool temp = L2_last_state;
            L2_last_state = controller.get_digital(DIGITAL_L2);
            return L2_last_state && !temp;
        }
        case DIGITAL_R2:{
            bool temp = R2_last_state;
            R2_last_state = controller.get_digital(DIGITAL_R2);
            return R2_last_state && !temp;
        }
        case DIGITAL_UP:{
            bool temp = up_last_state;
            up_last_state = controller.get_digital(DIGITAL_UP);
            return up_last_state && !temp;
        }
        case DIGITAL_DOWN:{
            bool temp = down_last_state;
            down_last_state = controller.get_digital(DIGITAL_DOWN);
            return down_last_state && !temp;
        }
        case DIGITAL_LEFT:{
            bool temp = left_last_state;
            left_last_state = controller.get_digital(DIGITAL_LEFT);
            return left_last_state && !temp;
        }
        case DIGITAL_RIGHT:{
            bool temp = right_last_state;
            right_last_state = controller.get_digital(DIGITAL_RIGHT);
            return right_last_state && !temp;
        }
        case DIGITAL_X:{
            bool temp = X_last_state;
            X_last_state = controller.get_digital(DIGITAL_X);
            return X_last_state && !temp;
        }
        case DIGITAL_Y:{
            bool temp = Y_last_state;
            Y_last_state = controller.get_digital(DIGITAL_Y);
            return Y_last_state && !temp;
        }
        case DIGITAL_A:{
            bool temp = A_last_state;
            A_last_state = controller.get_digital(DIGITAL_A);
            return A_last_state && !temp;
        }
        case DIGITAL_B:{
            bool temp = B_last_state;
            B_last_state = controller.get_digital(DIGITAL_B);
            return B_last_state && !temp;
        }
        default:
            return false;
    }
}

bool DriveControl::ControllerStates::is_pressed(pros::controller_digital_e_t button){
    switch(button){
        case DIGITAL_L1:{
            L1_last_state = controller.get_digital(DIGITAL_L1);
            return L1_last_state;
        }
        case DIGITAL_R1:{
            R1_last_state = controller.get_digital(DIGITAL_R1);
            return R1_last_state;
        }
        case DIGITAL_L2:{
            L2_last_state = controller.get_digital(DIGITAL_L2);
            return L2_last_state;
        }
        case DIGITAL_R2:{
            R2_last_state = controller.get_digital(DIGITAL_R2);
            return R2_last_state;
        }
        case DIGITAL_UP:{
            up_last_state = controller.get_digital(DIGITAL_UP);
            return up_last_state;
        }
        case DIGITAL_DOWN:{
            down_last_state = controller.get_digital(DIGITAL_DOWN);
            return down_last_state;
        }
        case DIGITAL_LEFT:{
            left_last_state = controller.get_digital(DIGITAL_LEFT);
            return left_last_state;
        }
        case DIGITAL_RIGHT:{
            right_last_state = controller.get_digital(DIGITAL_RIGHT);
            return right_last_state;
        }
        case DIGITAL_X:{
            X_last_state = controller.get_digital(DIGITAL_X);
            return X_last_state;
        }
        case DIGITAL_Y:{
            Y_last_state = controller.get_digital(DIGITAL_Y);
            return Y_last_state;
        }
        case DIGITAL_A:{
            A_last_state = controller.get_digital(DIGITAL_A);
            return A_last_state;
        }
        case DIGITAL_B:{
            B_last_state = controller.get_digital(DIGITAL_B);
            return B_last_state;
        }
        default:
            return false;
    }
}

void DriveControl::update_drive_train(){
    DriveTrain::move_velocity(Utilities::drive_control_map(controller.get_analog(ANALOG_LEFT_Y))*600.0,Utilities::drive_control_map(controller.get_analog(ANALOG_RIGHT_Y))*600.0);
}

void DriveControl::update_intake(){
    if(controller.get_digital(DIGITAL_L2)){
		Intake::run(600);
	}
	else if(controller.get_digital(DIGITAL_R2)){
		Intake::run(-600);
	}
	else{
		Intake::coast(); 
	}

	if(ControllerStates::is_activated(DIGITAL_R1)){
		Intake::togglePneumatic(State::Toggle);
	}
}

void DriveControl::update_catapult(){
    //pros::screen::print(pros::E_TEXT_MEDIUM,0, "Catapult: %f", catapultDistanceSensor.get());
    if(ControllerStates::is_pressed(DIGITAL_L1)){
		catapultFlung=false;
		catapultMoving = true;
	}
	if ((catapultFlung&&catapultDistanceSensor.get() < 100)||ControllerStates::is_pressed(DIGITAL_B)){
		catapultMoving = false;
	}
	if(catapultDistanceSensor.get() > 100){
		catapultFlung = true;
	}

	if(catapultMoving){
		Catapult::run_velocity(1);
	}
	else{
		Catapult::brake();
	}
}

void DriveControl::update_wings(){
    if(ControllerStates::is_activated(DIGITAL_X)){
        Wings::toggle(State::Toggle);
    }
}

void DriveControl::update_pto(){
    if(ControllerStates::is_activated(DIGITAL_UP)){
        PTO::toggle(State::On);
    }
    else if (ControllerStates::is_activated(DIGITAL_DOWN)){
        PTO::toggle(State::Off);
    }
}

void DriveControl::update(){
    update_drive_train();
    update_intake();
    update_catapult();
    update_wings();
    update_pto();
}