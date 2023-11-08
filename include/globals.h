#pragma once
#include "main.h"

extern::pros::Controller controller;

//wheels
extern::pros::Motor leftWheel1;
extern::pros::Motor leftWheel2;
extern::pros::Motor_Group leftWheels;

extern::pros::Motor rightWheel1;
extern::pros::Motor rightWheel2;
extern::pros::Motor_Group rightWheels;

//catapult
extern::pros::Motor catapultMotor1;
extern::pros::Motor catapultMotor2;
extern::pros::Rotation catapultRotation;

//intake
extern::pros::Motor intakeMotor;

//odometry wheel
extern::pros::Rotation leftOdometryWheel;
extern::pros::Rotation rightOdometryWheel;
extern::pros::Rotation backOdometryWheel;

//wings
extern::pros::ADIDigitalOut wingsPneumatic;

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