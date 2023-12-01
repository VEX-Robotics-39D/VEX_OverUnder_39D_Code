#include "main.h"
pros::Controller controller(CONTROLLER_MASTER);

//wheels
pros::Motor leftWheel1(4);
pros::Motor leftWheel2(5);
pros::Motor leftWheel3(6);
pros::Motor_Group leftWheels{leftWheel1,leftWheel2,leftWheel3};

pros::Motor rightWheel1(1,true);
pros::Motor rightWheel2(2,true);
pros::Motor rightWheel3(3,true);

pros::Motor_Group rightWheels{rightWheel1,rightWheel2,rightWheel3};

//catapult
pros::Motor flystickSpin(1, true);
pros::Motor flystickMovement(2);
pros::Rotation flystickRotation(3);

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


