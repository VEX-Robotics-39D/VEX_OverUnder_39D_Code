#pragma once
#include "main.h"

extern::pros::Controller controller;

//wheels
extern::pros::Motor leftWheel1;
extern::pros::Motor leftWheel2;
extern::pros::Motor leftWheel3;
extern::pros::Motor_Group leftWheels2;

extern::pros::Motor rightWheel1;
extern::pros::Motor rightWheel2;
extern::pros::Motor rightWheel3;
extern::pros::Motor_Group rightWheels2;

//catapult
extern::pros::Motor catapultMotor;
extern::pros::Distance catapultDistanceSensor;

//intake
extern::pros::Motor intakeMotor;

//odometry wheel
extern::pros::Rotation odometryWheel;

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