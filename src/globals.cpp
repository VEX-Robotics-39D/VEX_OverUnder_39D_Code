#include "main.h"
pros::Controller controller(CONTROLLER_MASTER);

//wheels
pros::Motor leftWheel1(5);
pros::Motor leftWheel2(4);
pros::Motor leftWheel3(3);
pros::Motor_Group leftWheels{leftWheel1,leftWheel2,leftWheel3};

pros::Motor rightWheel1(10);
pros::Motor rightWheel2(9);
pros::Motor rightWheel3(8);
pros::Motor_Group rightWheels{rightWheel1,rightWheel2,rightWheel3};

//catapult
pros::Motor catapultMotor(1);

//intake
pros::Motor intakeMotor(6);