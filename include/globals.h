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
extern::pros::Motor flyWheel;
extern::pros::Motor flystickRotate;

//intake
extern::pros::Motor intakeMotor;

//odometry wheel
extern::pros::Rotation backOdometryWheel;

//wings
extern::pros::ADIDigitalOut wingsPneumatic1;
extern::pros::ADIDigitalOut wingsPneumatic2;

//intake pneumatic
extern::pros::ADIDigitalOut intakePneumatic;

enum class State{
    Off,
    On,
    Toggle
};

extern::pros::Imu inertial;

const int UPDATE_INTERVAL=10;

extern::pros::Rotation backRotation;

extern::lemlib::TrackingWheel backTrackingWheel;

extern::lemlib::Drivetrain_t drivetrain;

extern::lemlib::TrackingWheel backTrackingWheel;

extern::lemlib::Drivetrain_t drivetrain;
extern::lemlib::OdomSensors_t odomSensors;

extern::lemlib::ChassisController_t lateralController;
extern::lemlib::ChassisController_t angularController;
extern::lemlib::Chassis chassis;


