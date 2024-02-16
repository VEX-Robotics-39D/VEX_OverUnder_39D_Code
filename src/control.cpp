#include "main.h"

bool Control::ControllerStates::L1_last_state = false;
bool Control::ControllerStates::R1_last_state = false;
bool Control::ControllerStates::L2_last_state = false;
bool Control::ControllerStates::R2_last_state = false;
bool Control::ControllerStates::up_last_state = false;
bool Control::ControllerStates::down_last_state = false;
bool Control::ControllerStates::left_last_state = false;
bool Control::ControllerStates::right_last_state = false;
bool Control::ControllerStates::X_last_state = false;
bool Control::ControllerStates::Y_last_state = false;
bool Control::ControllerStates::A_last_state = false;
bool Control::ControllerStates::B_last_state = false;

bool Control::ControllerStates::is_activated(pros::controller_digital_e_t button){
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

bool Control::ControllerStates::is_pressed(pros::controller_digital_e_t button){
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
static bool activated = false;
void Control::update_drive_train_tank(){
    leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    DriveTrain::move_velocity(Utilities::drive_control_map(controller.get_analog(ANALOG_LEFT_Y))*600.0,Utilities::drive_control_map(controller.get_analog(ANALOG_RIGHT_Y))*600.0);
    if(Utilities::drive_control_map(controller.get_analog(ANALOG_LEFT_X)) < -0.8){
        leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
        leftWheels.move_velocity(0);
    }
    if(Utilities::drive_control_map(controller.get_analog(ANALOG_RIGHT_X)) > 0.8){
        rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
        rightWheels.move_velocity(0);
    }

}

void Control::update_drive_train_arcade(){
    DriveTrain::move_velocity(Utilities::drive_control_map(controller.get_analog(ANALOG_LEFT_Y)+controller.get_analog(ANALOG_LEFT_X))*600.0,
                            Utilities::drive_control_map(controller.get_analog(ANALOG_LEFT_Y)-controller.get_analog(ANALOG_LEFT_X))*600.0);
}
void Control::update_intake(){
    if(ControllerStates::is_pressed(DIGITAL_L1)){
		Intake::run(600);
	}
	else if(ControllerStates::is_pressed(DIGITAL_L2)){
		Intake::run(-600);
	}
	else{
		Intake::coast(); 
	}
}

static bool lastPressed1 = false, lastPressed2 = false;
void Control::update_wings(){
    if(ControllerStates::is_pressed(DIGITAL_R1)){
        if (!lastPressed1){
            Wings::toggle1(State::Toggle);
            lastPressed1 = true;
        }
    }
    else{
        lastPressed1 = false;
    }

    if(ControllerStates::is_pressed(DIGITAL_R2)){
        if (!lastPressed2){
            Wings::toggle2(State::Toggle);
            lastPressed2 = true;
        }
    }
    else{
        lastPressed2 = false;
    }
}

void Control::debug(){
    pros::screen::print(pros::E_TEXT_MEDIUM, 1, "X: %f", Odometry::x);
    pros::screen::print(pros::E_TEXT_MEDIUM, 2, "Y: %f", Odometry::y);
    pros::screen::print(pros::E_TEXT_MEDIUM, 4, "Theta: %f", Odometry::theta * 180.0/PI);
}

void Control::update_catapult(){
    if (ControllerStates::is_pressed(DIGITAL_A)){
        Catapult::spinCata();
    }
    else{
        Catapult::stopCata();
    }
}

void Control::update_hang(){
    if(ControllerStates::is_activated(DIGITAL_X)){
        Hang::toggle(State::Toggle);
    }

}

void Control::update(){
    Odometry::update();
    update_drive_train_tank();
    // update_drive_train_arcade();
    update_catapult();
    update_hang();
    update_intake();
    update_wings();
    debug();         
}