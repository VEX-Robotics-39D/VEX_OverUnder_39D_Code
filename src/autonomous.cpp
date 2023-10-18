#include "main.h"

void Autonomous::Routines::common_1_0(){
    PTO::toggle(State::On);
    Intake::togglePneumatic(State::On);
	pros::screen::set_pen(COLOR_BLUE);
}

void Autonomous::Routines::test_angle_PID(){
    DriveTrain::Control::AnglePID::set_target(90);
    while(true){
        Odometry::updateInertial();
        pros::screen::print(pros::E_TEXT_MEDIUM ,0, "Theta: %f", Odometry::getTheta());
        DriveTrain::Control::AnglePID::update();
        pros::delay(10);
    }
}

void Autonomous::Routines::test_distance_PID(){
    DriveTrain::Control::DistancePID::new_route();
    DriveTrain::Control::DistancePID::set_target(1000);
    while(true){
        DriveTrain::Control::DistancePID::update();
        pros::delay(10);
    }
}