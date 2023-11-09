#include "main.h"
pros::Controller controller(CONTROLLER_MASTER);

//wheels
pros::Motor leftWheel1(20);
pros::Motor leftWheel2(19);
pros::Motor_Group leftWheels{leftWheel1,leftWheel2};

pros::Motor rightWheel1(10,true);
pros::Motor rightWheel2(9,true);
pros::Motor_Group rightWheels{rightWheel1,rightWheel2};

//catapult
pros::Motor catapultMotor1(1,true);
pros::Motor catapultMotor2(2);

pros::Rotation catapultRotation(3);

//intake
pros::Motor intakeMotor(18,true);

//odometry wheel
pros::Rotation leftOdometryWheel(4);
pros::Rotation rightOdometryWheel(5,true);
pros::Rotation backOdometryWheel(3);

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

lemlib::TrackingWheel leftTrackingWheel(&leftOdometryWheel, 4.0, 3.25);
lemlib::TrackingWheel rightTrackingWheel(&rightOdometryWheel, 4.0, -3.25);
lemlib::TrackingWheel backTrackingWheel(&backOdometryWheel, 4.0, 0.0);

lemlib::OdomSensors_t odomSensors{
    &leftTrackingWheel,
    &rightTrackingWheel,
    &backTrackingWheel,
    nullptr,
    &inertial
};


