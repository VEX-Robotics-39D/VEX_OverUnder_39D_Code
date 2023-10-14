#include "main.h"

void Autonomous::Routines::common_1_0(){
    PTO::toggle(State::On);
    Intake::togglePneumatic(State::On);
	Catapult::L1_Pressed = true;
	Catapult::flung = false;
	pros::screen::set_pen(COLOR_BLUE);
	Intake::R1pressed=false;
}

void Autonomous::Routines::test_PID_theta(){
    DriveTrain::Control::AnglePID::set_target(90);
    while(true){
        Odometry::updateInertial();
        DriveTrain::Control::AnglePID::update();
        pros::delay(10);
    }
}