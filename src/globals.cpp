#include "main.h"
pros::Controller controller(CONTROLLER_MASTER);

//wheels
pros::Motor leftWheel1(10,true);
pros::Motor leftWheel2(9,true);
pros::Motor_Group leftWheels{leftWheel1,leftWheel2};

pros::Motor rightWheel1(20);
pros::Motor rightWheel2(19);
pros::Motor_Group rightWheels{rightWheel1,rightWheel2};

//catapult
pros::Motor catapultMotor(1);
pros::Distance catapultDistanceSensor(2);
//intake
pros::Motor intakeMotor(6,true);

//odometry wheel
pros::Rotation odometryWheel(7);

//wings
pros::ADIDigitalOut wingsPneumatic('A');

//pto
pros::ADIDigitalOut pto('B');

//intake pneumatic
pros::ADIDigitalOut intakePneumatic('C');

//inertial sensor
pros::Imu inertial(3);

lemlib::Drivetrain_t drivetrain{
    &leftWheels,
    &rightWheels,
    12.0,
    3.25,
    1000.0/3.0,
};


