#pragma once
#include<main.h>

pros::Controller controller(CONTROLLER_MASTER);

pros::Motor leftWheel1(1);
pros::Motor leftWheel2(2);
pros::Motor leftWheel3(3);
pros::Motor_Group leftWheels({leftWheel1,leftWheel2,leftWheel3});

pros::Motor rightWheel1(4);
pros::Motor rightWheel2(5);
pros::Motor rightWheel3(6);
pros::Motor_Group rightWheels({rightWheel1,rightWheel2,rightWheel3});

class DriveTrain{
    static void move(){

    }
};