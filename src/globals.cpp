#include "main.h"
pros::Controller controller(CONTROLLER_MASTER);

//wheels
pros::Motor leftWheel1(4,true);
pros::Motor leftWheel2(5,true);
pros::Motor leftWheel3(6,true);
pros::Motor_Group leftWheels{leftWheel1,leftWheel2,leftWheel3};

pros::Motor rightWheel1(1);
pros::Motor rightWheel2(2);
pros::Motor rightWheel3(3);

pros::Motor_Group rightWheels{rightWheel1,rightWheel2,rightWheel3};

//catapult
pros::Motor flystickSpin(11, true);
pros::Motor flystickMovement(10, true);

//intake
pros::Motor intakeMotor(7,true);


//wings
pros::ADIDigitalOut wingsPneumatic1('A');
pros::ADIDigitalOut wingsPneumatic2('C');

//pto
pros::ADIDigitalOut pto('B');

//inertial sensor
pros::Imu inertial(12);

lemlib::Drivetrain_t drivetrain{
    &leftWheels,
    &rightWheels,
    12.0,
    3.25,
    1000.0/3.0,
};

lemlib::OdomSensors_t odomSensors{
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    &inertial
};

lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};
 
 
// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, odomSensors);



