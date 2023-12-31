#include "main.h"

pros::Controller controller(CONTROLLER_MASTER);

//wheels
pros::Motor leftWheel1(4,true);
pros::Motor leftWheel2(5,true);
pros::Motor leftWheel3(6);
pros::Motor_Group leftWheels{leftWheel1,leftWheel2,leftWheel3};

pros::Motor rightWheel1(1);
pros::Motor rightWheel2(2);
pros::Motor rightWheel3(3,true);
pros::Motor_Group rightWheels{rightWheel1,rightWheel2,rightWheel3};

//flystick
pros::Motor flyWheel(13);
pros::Motor flystick(10);

//intake
pros::Motor intakeMotor(7);
pros::ADIDigitalOut intakePneumatic('B');

//wings
pros::ADIDigitalOut wingsPneumatic1('C');
pros::ADIDigitalOut wingsPneumatic2('A');

//sensors
pros::Imu inertial(12);

pros::Rotation backRotation(13);

//lemlib
lemlib::Drivetrain_t drivetrain{
    &leftWheels,
    &rightWheels,
    11.5,
    3.25,
    360,
};

lemlib::TrackingWheel backTrackingWheel(&backRotation, 2.75,  3.75);

lemlib::OdomSensors_t odomSensors{
    nullptr,
    nullptr,
    //nullptr,
    &backTrackingWheel,
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
 
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};
 
lemlib::Chassis chassis(drivetrain, lateralController, angularController, odomSensors);



