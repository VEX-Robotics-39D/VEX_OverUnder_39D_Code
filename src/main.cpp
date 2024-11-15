#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {

	
	//print position
	

	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello World!");
	pros::lcd::set_text(2, "I definitely do not control my human builders.");
	pros::lcd::register_btn1_cb(on_center_button);


	
	pros::screen::set_pen(COLOR_BLUE);
	// chassis.calibrate();
	
	inertial.reset(true);
	inertial.tare_heading();
	inertial.tare_rotation();
	Odometry::init();
}


/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous(){
	//Autonomous::Routes::skillauton();
	// chassis.setPose(0,0,0);
	// Autonomous::PID::driveTo(0,24);
	// pros::delay(2000);
	// Autonomous::PID::turnTo(45);
	// Autonomous::PID::turnTo(90);
	// Autonomous::PID::turnTo(135);
	// Autonomous::PID::turnTo(180);
	// Autonomous::PID::turnTo(225);
	// Autonomous::PID::turnTo(270);
	// Autonomous::PID::turnTo(315);
	Autonomous::Routes::matchWinPointAuton();

	// Autonomous::PID::driveTo(0,5);
	// Autonomous::PID::driveTo(10,10);
	// Odometry::set_theta(90);

    // Autonomous::PID::turnThenMoveTo(10,10,0.03,0.4,);
	// Autonomous::PID::turnTo(0,1.0);
	// Autonomous::Routes::skillsAuton();
	
	// Autonomous::Routes::testpid();
	// Autonomous::PID::turnThenMoveTo(10,10, false);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
	// run this for driver auton
	
	// Odometry::set_theta(135);
    // Odometry::set_x(3);
    // Odometry::set_y(-12);
	// Catapult::spinCata();
    // pros::delay(500);
    // Catapult::stopCata();
	// Autonomous::PID::driveTo(15,-25,0.5,100,false);
    // Autonomous::PID::turnTo(72,1,200);

    // Wings::toggle2(State::Off);
	
	// Catapult::spinCata();
    // pros::delay(500);
    // Catapult::stopCata();
	
	while (true) {
		Control::update();
		pros::delay(DRIVE_UPDATE_INTERVAL);
	}
}
