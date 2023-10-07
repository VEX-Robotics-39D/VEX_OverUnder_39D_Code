#pragma once
#include "main.h"

extern::pros::Controller controller;

//wheels
extern::pros::Motor leftWheel1;
extern::pros::Motor leftWheel2;
extern::pros::Motor leftWheel3;
extern::pros::Motor_Group leftWheels3;
extern::pros::Motor_Group leftWheels2;

extern::pros::Motor rightWheel1;
extern::pros::Motor rightWheel2;
extern::pros::Motor rightWheel3;
extern::pros::Motor_Group rightWheels3;
extern::pros::Motor_Group rightWheels2;

//catapult
extern::pros::Motor catapultMotor;

//intake
extern::pros::Motor intakeMotor;

//odometry wheel
extern::pros::Rotation odometryWheel;

//wings
extern::pros::ADIDigitalOut leftWing;
extern::pros::ADIDigitalOut rightWing;

//pto
extern::pros::ADIDigitalOut pto;
