#include "main.h"

void Autonomous::run(int time){
    pros::screen::print(pros::E_TEXT_MEDIUM ,0, "Autonomous running for %d ms", time);
    for(int i=1; i<=time/UPDATE_INTERVAL; i++){
        Odometry::updateInertial();
        DriveTrain::Control::AnglePID::update();
        DriveTrain::Control::DistancePID::update();
        pros::delay(UPDATE_INTERVAL);
    }
}

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

void Autonomous::Routines::match_op(){
    inertial.set_rotation(45);
    PTO::toggle(State::Off);
    Catapult::run_velocity(30);
    DriveTrain::Control::AnglePID::set_state(State::Off);
    DriveTrain::Control::DistancePID::set_state(State::Off);
    run(1500);
    DriveTrain::Control::DistancePID::set_state(State::On);
    DriveTrain::Control::DistancePID::new_route();
    DriveTrain::Control::DistancePID::set_target(750);
    run(750);
    Catapult::run_velocity(0);
    DriveTrain::Control::DistancePID::set_state(State::Off);
    DriveTrain::Control::AnglePID::set_state(State::On);
    DriveTrain::Control::AnglePID::set_target(0);
    run(750);
    Intake::run(-600); 
    DriveTrain::Control::AnglePID::set_state(State::Off);
    DriveTrain::move_velocity(600,600);
    run(750);
    //DriveTrain::move_velocity(300,300);
    //run(7500);
    DriveTrain::Control::DistancePID::set_state(State::On);
    DriveTrain::Control::DistancePID::new_route();
    DriveTrain::Control::DistancePID::set_target(-600);
    run(750);
    Intake::coast();
    DriveTrain::Control::DistancePID::set_state(State::Off);
    DriveTrain::Control::AnglePID::set_state(State::On);
    DriveTrain::Control::AnglePID::set_target(-70);
    run(1000); 
    
    DriveTrain::Control::AnglePID::set_state(State::Off);
    DriveTrain::Control::DistancePID::set_state(State::On);
    DriveTrain::Control::DistancePID::new_route();
    DriveTrain::Control::DistancePID::set_target(2200);
    run(1500);
    Intake::coast();
    DriveTrain::Control::DistancePID::set_state(State::Off);
    DriveTrain::Control::AnglePID::set_state(State::On);
    DriveTrain::Control::AnglePID::set_target(60);
    run(1000);
    Intake::run(-600);
    pros::delay(300);
    Intake::coast();
    DriveTrain::Control::AnglePID::set_target(-30);
    run(1000);
    DriveTrain::Control::AnglePID::set_state(State::Off);
    DriveTrain::Control::DistancePID::set_state(State::On);
    DriveTrain::Control::DistancePID::new_route();
    DriveTrain::Control::DistancePID::set_target(500);
    run(900);
    Intake::run(400);
    pros::delay(300);
    Intake::coast();
    DriveTrain::Control::DistancePID::set_state(State::Off);
    DriveTrain::Control::AnglePID::set_state(State::On);
    DriveTrain::Control::AnglePID::set_target(90);
    run(1000);
    Intake::run(-600);
    pros::delay(300);
    DriveTrain::Control::AnglePID::set_target(-105);
    run(1250);
    Wings::toggle(State::On);
    DriveTrain::Control::AnglePID::set_state(State::Off);
    DriveTrain::Control::DistancePID::set_state(State::On);
    DriveTrain::Control::DistancePID::new_route();
    DriveTrain::Control::DistancePID::set_target(-2000);
    run(2000);
}

void Autonomous::Routines::match_af(){

}

