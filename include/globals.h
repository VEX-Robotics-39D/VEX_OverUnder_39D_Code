#pragma once
#include "main.h"

enum class State{
    Off,
    On,
    Toggle
};

//constants
const int DRIVE_UPDATE_INTERVAL=10;
const int AUTON_UPDATE_INTERVAL=10;

const double PI=3.141592653589793238462643383279502884197169399375105820974944592307816406286;

const double TRACK_WIDTH = 10.375;

extern pros::Controller controller;

//catapult
extern pros::Motor catapult;

//hang

extern pros::ADIDigitalOut hangPneumatic;

//wheels
extern pros::Motor leftWheel1;
extern pros::Motor leftWheel2;
extern pros::Motor leftWheel3;
extern pros::Motor_Group leftWheels;

extern pros::Motor rightWheel1;
extern pros::Motor rightWheel2;
extern pros::Motor rightWheel3;
extern pros::Motor_Group rightWheels;

//intake
extern pros::Motor intakeMotor;
extern pros::Motor flywheel;

//odometry wheel
extern pros::Rotation backOdometryWheel;
extern pros::Rotation leftOdometryWheel;
extern pros::Rotation rightOdometryWheel;

//wings
extern pros::ADIDigitalOut wingsPneumatic1;
extern pros::ADIDigitalOut wingsPneumatic2;

//intake pneumatic
extern pros::ADIDigitalOut intakePneumatic;

//sensors
extern pros::Imu inertial;

extern pros::Rotation backRotation;

//lemlib
extern lemlib::TrackingWheel backTrackingWheel;

extern lemlib::Drivetrain_t drivetrain;

extern lemlib::OdomSensors_t odomSensors;

extern lemlib::ChassisController_t lateralController;
extern lemlib::ChassisController_t angularController;
extern lemlib::Chassis chassis;


