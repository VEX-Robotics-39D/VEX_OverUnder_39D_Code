#pragma once
#include "main.h"

extern::pros::Controller controller;

//wheels
extern::pros::Motor leftWheel1;
extern::pros::Motor leftWheel2;
extern::pros::Motor leftWheel3;
extern::pros::Motor_Group leftWheels;

extern::pros::Motor rightWheel1;
extern::pros::Motor rightWheel2;
extern::pros::Motor rightWheel3;
extern::pros::Motor_Group rightWheels;

//flystick
extern::pros::Motor flystickSpin;
extern::pros::Motor flystickMovement;

//intake
extern::pros::Motor intakeMotor;

//odometry wheel
extern::pros::Rotation leftOdometryWheel;
extern::pros::Rotation rightOdometryWheel;
extern::pros::Rotation backOdometryWheel;

//wings
extern::pros::ADIDigitalOut wingsPneumatic1;
extern::pros::ADIDigitalOut wingsPneumatic2;

//pto
extern::pros::ADIDigitalOut pto;

//intake pneumatic
extern::pros::ADIDigitalOut intakePneumatic;

enum class State{
    Off,
    On,
    Toggle
};

extern::pros::Imu inertial;

const int UPDATE_INTERVAL=10;

extern::lemlib::Drivetrain_t drivetrain;

extern::lemlib::TrackingWheel leftTrackingWheel;
extern::lemlib::TrackingWheel rightTrackingWheel;
extern::lemlib::TrackingWheel backTrackingWheel;

extern::lemlib::Drivetrain_t drivetrain;
extern::lemlib::OdomSensors_t odomSensors;

extern::lemlib::ChassisController_t lateralController;
extern::lemlib::ChassisController_t angularController;
extern::lemlib::Chassis chassis;


