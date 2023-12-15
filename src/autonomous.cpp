#include "main.h"

ASSET(path_txt);

void Autonomous::Routes::testpid(){
    chassis.setPose(0,0,0);
    PID::turnTo(20);
}

ASSET(aff1_txt);

void Autonomous::Routes::oppauton(){
    Intake::run(600);
    chassis.setPose(12,-60,-90);
    chassis.follow(aff1_txt,4000,15,false,false);
    Intake::run(0);
    chassis.moveTo(60,-40,0,2000);
    Intake::run(-600);
    chassis.moveTo(60,-30,0,1000);
    chassis.moveTo(60,-40,0,1000);
    chassis.turnTo(15,-28,1000);
    chassis.moveTo(15,-28,0,2000);

}

ASSET(skill1_txt);
ASSET(skill2_txt);
ASSET(skill3_txt);
ASSET(skill4_txt);
ASSET(skill5_txt);
ASSET(matchAutonpt1_txt);
ASSET(matchAutonpt2_txt);

void Autonomous::Routes::skillauton(){
    chassis.setPose(53,-46,-90);
    chassis.follow(skill1_txt,10000,15);
    DriveTrain::move_velocity(600,600);
    pros::delay(500);
    DriveTrain::move_velocity(0,0);
    chassis.follow(skill2_txt,10000,15,false,false);
    DriveTrain::move_velocity(-600,-600);
    pros::delay(500);
    DriveTrain::move_velocity(0,0);
    chassis.follow(skill3_txt,6000,15);
    chassis.follow(skill4_txt,6000,15);
    DriveTrain::move_velocity(600,600);
    pros::delay(500);
    DriveTrain::move_velocity(0,0);
    chassis.follow(skill5_txt,10000,15,false,false);
    DriveTrain::move_velocity(600,600);
    pros::delay(500);
    DriveTrain::move_velocity(0,0);
}

void Autonomous::Routes::moveForward(){
    chassis.moveTo(1000,0,0,10000);
    pros::delay(5000);
    chassis.moveTo(0,0,0,10000);
}

void Autonomous::Routes::matchWinPointAuton(){
    chassis.setPose(-60,30,208);
    Wings::toggle2(State::On);
    chassis.follow(matchAutonpt1_txt,6000,15);
    Wings::toggle2(State::Off);
    flystickRotate.move_absolute(1300,200);
    chassis.follow(matchAutonpt2_txt,6000,15);
}

double Autonomous::PID::turnKP = 1.1;
double Autonomous::PID::turnKI = 0.002;
double Autonomous::PID::turnKD = 1.1;
double Autonomous::PID::driveKP = 15;
double Autonomous::PID::driveKI = 0.005;
double Autonomous::PID::driveKD = 1;
double Autonomous::PID::turnError = 0.0;
double Autonomous::PID::driveError = 0.0;
double Autonomous::PID::turnIntegral = 0.0;
double Autonomous::PID::driveIntegral = 0.0;
double Autonomous::PID::turnDerivative = 0.0;
double Autonomous::PID::driveDerivative = 0.0;
double Autonomous::PID::turnLastError = 0.0;
double Autonomous::PID::driveLastError = 0.0;


void Autonomous::PID::turnTo(double angle){
    while (true)
    {
        //pros::screen::print(pros::E_TEXT_MEDIUM, 1, "theta: %f", chassis.getPose().theta);
        turnError = angle - Odometry::get_theta();
        turnIntegral*=0.985;
        turnIntegral += turnError;
        if(turnError*turnLastError < 0) turnIntegral = 0;
        turnDerivative = turnError - turnLastError;
        double turn = turnKP*turnError + turnKI*turnIntegral + turnKD*turnDerivative;
        DriveTrain::move_velocity(-turn,turn);
        if(fabs(turnError)<1.2&&fabs(turnError-turnLastError)<0.01){
            rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            DriveTrain::move_velocity(0,0);
            break;
        }
        turnLastError = turnError;
        pros::delay(5);
    }
    
}

void Autonomous::PID::driveTo(double x,double y){
    chassis.setPose(0,0,0);
    while (true)
    {
        double xDiffernece = x-Odometry::get_x();
        double yDifference = y-Odometry::get_y();
        driveError = sqrt(xDiffernece*xDiffernece+yDifference*yDifference)*cos(atan2(yDifference,xDiffernece)-Odometry::get_theta()/180*3.1415926535897932);
        pros::screen::print(pros::E_TEXT_MEDIUM, 1, "driveError: %f", driveError);
        pros::screen::print(pros::E_TEXT_MEDIUM, 2, "x: %f", Odometry::get_x());
        pros::screen::print(pros::E_TEXT_MEDIUM, 3, "y: %f", Odometry::get_y());
        pros::screen::print(pros::E_TEXT_MEDIUM, 4, "length: %f", atan2(yDifference,xDiffernece));
        pros::screen::print(pros::E_TEXT_MEDIUM, 5, "length: %f", Odometry::get_theta()/180*3.1415926535897932);
        driveIntegral*=0.985;
        driveIntegral += driveError;
        if(driveError*driveLastError < 0) driveIntegral = 0;
        driveDerivative = driveError - driveLastError;
        double drive = driveKP*driveError + driveKI*driveIntegral - driveKD*driveDerivative;
        //DriveTrain::move_velocity(drive,drive);
        if(fabs(driveError)<0.8&&fabs(driveError-driveLastError)<0.002){
            rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            DriveTrain::move_velocity(0,0);
            //break;
        }
        driveLastError = driveError;
        pros::delay(5);
    }


}

void Autonomous::PID::turnThenMoveTo(double x,double y){
    //turn first
    double PI=3.141592653589793238462643383279502884197169399375105820974944592307816406286;
    double angle = atan2(y-Odometry::get_y(),x-Odometry::get_x())*180/PI;
    pros::screen::print(pros::E_TEXT_MEDIUM, 1, "X: %f", x-Odometry::get_x());
    pros::screen::print(pros::E_TEXT_MEDIUM, 2, "Y: %f", y-Odometry::get_y());
    //return;
    double difference=angle-Odometry::get_theta();
    while(difference>180) difference-=360;
    while(difference<-180) difference+=360;
    pros::screen::print(pros::E_TEXT_MEDIUM, 3, "Y: %f", Odometry::get_theta()+difference);
    //return;
    turnTo(Odometry::get_theta()+difference);
    //then move
    driveTo(x,y);

}