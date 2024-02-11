#include "main.h"

pros::Controller controller(CONTROLLER_MASTER);

//catapult
pros::Motor catapult(5, true);

//wheels
pros::Motor leftWheel1(10,true);
pros::Motor leftWheel2(9,true);
pros::Motor leftWheel3(8,true);
pros::Motor_Group leftWheels{leftWheel1,leftWheel2,leftWheel3};

pros::Motor rightWheel1(1);
pros::Motor rightWheel2(2);
pros::Motor rightWheel3(3);
pros::Motor_Group rightWheels{rightWheel1,rightWheel2,rightWheel3};

//intake
pros::Motor intakeMotor(4, true);
pros::ADIDigitalOut intakePneumatic('B');

//wings
// pros::ADIDigitalOut wingsPneumatic1('');
// pros::ADIDigitalOut wingsPneumatic2('');

//hang
pros::ADIDigitalOut hangPneumatic('C');

//sensors
pros::Imu inertial(14);

pros::Rotation backRotation(14);
pros::Rotation leftRotation(15);
pros::Rotation rightRotation(16);

//lemlib
lemlib::Drivetrain_t drivetrain{
    &leftWheels,
    &rightWheels,
    10.375,
    3.25,
    360,
};

lemlib::TrackingWheel backTrackingWheel(&backRotation, 2.75,  1.5625, 1.66666666666666666666);

lemlib::OdomSensors_t odomSensors{
    nullptr,
    nullptr,
    // nullptr,
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



