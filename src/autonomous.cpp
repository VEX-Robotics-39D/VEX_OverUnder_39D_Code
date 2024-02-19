#include "main.h"




// void Autonomous::Routes::matchWinPointAuton(){
//     chassis.setPose(-60,30,208);
//     Wings::toggle2(State::On);
//     chassis.follow(matchAutonpt1_txt,6000,15);
//     Wings::toggle2(State::Off);
//     flystick.move_absolute(1300,200);
//     chassis.follow(matchAutonpt2_txt,6000,15);
// 

double Autonomous::PID::turnKP = 1.2;
double Autonomous::PID::turnKI = 0.001;
double Autonomous::PID::turnKD = 43.0;

double Autonomous::PID::driveKP = 8.0;
double Autonomous::PID::driveKI = 0.002;
double Autonomous::PID::driveKD = 0.0;

double Autonomous::PID::turnError = 0.0;
double Autonomous::PID::driveError = 0.0;
double Autonomous::PID::turnIntegral = 0.0;
double Autonomous::PID::driveIntegral = 0.0;
double Autonomous::PID::turnDerivative = 0.0;
double Autonomous::PID::driveDerivative = 0.0;
double Autonomous::PID::turnLastError = 10000;
double Autonomous::PID::driveLastError = 0.0;

double Autonomous::PID::turnSatisfactoryTime = 0.0;
double Autonomous::PID::driveSatisfactoryTime = 0.0;
double Autonomous::PID::fastMoveSatisfactoryTime = 0.0;

void Autonomous::PID::turnTo(double angle){
    while (true){
        Odometry::update();
        Control::debug();
        turnError = angle + (inertial.get_rotation());
        turnIntegral*=0.985;
        turnIntegral += turnError;
        if(turnError*turnLastError < 0) turnIntegral = 0;
        turnDerivative = turnError - turnLastError;
        double turn = turnKP*turnError + turnKI*turnIntegral + turnKD*turnDerivative;
        DriveTrain::move_velocity(-turn,turn);
        if(fabs(turnError)<1.2&&fabs(turnError-turnLastError)<0.01){
            if (turnSatisfactoryTime < 0.1){
                turnSatisfactoryTime += (double)AUTON_UPDATE_INTERVAL/1000.0;
            }
            else{
                rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
                leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
                DriveTrain::move_velocity(0,0);
                break;
            }
        }
        else{
            turnSatisfactoryTime = 0;
        }
        turnLastError = turnError;
        pros::delay(AUTON_UPDATE_INTERVAL);
    }
    
}

void Autonomous::PID::driveTo(double x,double y){
    while (true){ 
        Odometry::update();
        Control::debug();
        double xDiffernece = x-Odometry::get_x();
        double yDifference = y-Odometry::get_y();
        driveError = sqrt(xDiffernece*xDiffernece+yDifference*yDifference)*cos(atan2(yDifference,xDiffernece)-Odometry::get_theta());
        driveIntegral*=0.985;
        driveIntegral += driveError;
        if(driveError*driveLastError < 0) driveIntegral = 0;
        driveDerivative = driveError - driveLastError;
        double drive = driveKP*driveError + driveKI*driveIntegral - driveKD*driveDerivative;
        DriveTrain::move_velocity(drive,drive);
        if(fabs(driveError)<0.8&&fabs(driveError-driveLastError)<0.002){
            if (driveSatisfactoryTime < 0.1){
                driveSatisfactoryTime += (double)AUTON_UPDATE_INTERVAL/1000.0;
            }
            else{
                rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
                leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
                DriveTrain::move_velocity(0,0);
                break;
            }
        }
        else{
            driveSatisfactoryTime = 0;
        }
        driveLastError = driveError;
        pros::delay(AUTON_UPDATE_INTERVAL);
    }
}

void Autonomous::PID::turnThenMoveTo(double x,double y, bool opposite = false){
    //turn first
    double angle = atan2(y-Odometry::get_y(),x-Odometry::get_x());
    //return;
    double angleDifference = angle * 180/PI + inertial.get_rotation() + opposite * 180;
    while(angleDifference>180) angleDifference-=360;
    while(angleDifference<-180) angleDifference+=360;
    pros::screen::print(pros::E_TEXT_MEDIUM, 3, "theta: %f", Odometry::get_theta()+angleDifference);
    //return;
    
    pros::screen::print(pros::E_TEXT_MEDIUM, 9, "angle: %f", angle);
    pros::screen::print(pros::E_TEXT_MEDIUM, 10, "angleDifference: %f", angleDifference);
    turnTo(angleDifference);
    //then move
    driveTo(x,y);
}

void Autonomous::PID::fastMoveTo(double x,double y,double stopRadius){
    chassis.setPose(0,0,0);
    
}


void Autonomous::Routes::matchWinPointAuton(){
    Odometry::x = -6; Odometry::y = 6; inertial.set_rotation(45);
    Wings::toggle2(State::On); // wings on
    Autonomous::PID::driveTo(-12,0); // get triball from alliance zone
    Wings::toggle2(State::Off);// wings off
    Autonomous::PID::turnThenMoveTo(-28,-2);
    // idk how to do this without interrupting code but here is where I raise flystick
    Autonomous::PID::turnThenMoveTo(0,24);
    Autonomous::PID::turnThenMoveTo(0,36);
}
/*
void Autonomous::Routes::sixTriball(){
    chassis.setPose(-180,0,0);
    Intake::run(600);
    Autonomous::PID::turnThenMoveTo(0,-2);
    Intake::run(0);
    Autonomous::PID::turnThenMoveTo(0,24);
    Autonomous::PID::turnTo(45);
    Intake::run(-600);
    pros::delay(1.5);
    Intake::run(0);
    Autonomous::PID::turnThenMoveTo(-48,72);
    Autonomous::PID::turnThenMoveTo(-60,72);
    Autonomous::PID::turnThenMoveTo(-36,60);
    Intake::run(600);
    pros::delay(1.5);
    Intake::run(0);
    Autonomous::PID::turnThenMoveTo(-48,22);
    Intake::run(-600);
    pros::delay(1.5);
    Intake::run(0);
    Autonomous::PID::turnThenMoveTo(-72,0);
    Intake::run(600);
    pros::delay(1.5);
    Intake::run(0);
    Autonomous::PID::turnTo(0);
}

void Autonomous::Routes::nearRushMid(){
    chassis.setPose(45,-6,6);
    Autonomous::PID::driveTo(-72,72);
    Intake::run(600);
    Autonomous::PID::turnTo(180);
    Intake::run(-600);
    Autonomous::PID::driveTo(-50,12);
}
*/

void Autonomous::normalDrive::drive(double time){
    // seconds, not miliseconds
    
}

void Autonomous::Routes::skillsAuton(){
    Catapult::spinCata();
    pros::delay(30000);
    Catapult::stopCata();
    Autonomous::PID::turnThenMoveTo(0,24);
    Autonomous::PID::turnThenMoveTo(0,100);
    Autonomous::PID::turnThenMoveTo(24,120);
    Autonomous::PID::turnThenMoveTo(36,120);
    //
    l/-.[- ]
}
