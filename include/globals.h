#pragma once
#include "main.h"

enum class State{
    Off,
    On,
    Toggle
};

//constants
const int UPDATE_INTERVAL=10;

extern pros::Controller controller;

//catapult
extern pros::Motor catapult;

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

//odometry wheel
extern pros::Rotation backOdometryWheel;

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


