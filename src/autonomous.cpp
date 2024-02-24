#include "main.h"




// void Autonomous::Routes::matchWinPointAuton(){
//     chassis.setPose(-60,30,208);
//     Wings::toggle2(State::On);
//     chassis.follow(matchAutonpt1_txt,6000,15);
//     Wings::toggle2(State::Off);
//     flystick.move_absolute(1300,200);
//     chassis.follow(matchAutonpt2_txt,6000,15);
// 

double Autonomous::PID::turnKP = 1.0;
double Autonomous::PID::turnKI = 0.002;
double Autonomous::PID::turnKD = 0.0;

double Autonomous::PID::driveKP = 8.0;
double Autonomous::PID::driveKI = 0.005;
double Autonomous::PID::driveKD = 15.0;

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

void Autonomous::PID::turnTo(double angle,double error=1,int timeCap=200){
    int time=0;
    while (true){
        Odometry::update();
        Control::debug();
        turnError = angle + inertial.get_rotation();
        turnIntegral*=0.985;
        turnIntegral += turnError;
        if(turnError*turnLastError < 0) turnIntegral = 0;
        turnDerivative = turnError - turnLastError;
        double turn = turnKP*turnError + turnKI*turnIntegral + turnKD*turnDerivative;
        DriveTrain::move_velocity(-turn,turn);
        if((fabs(turnError)<error&&abs(turnDerivative)<0.05)||time>timeCap){
            leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            DriveTrain::move_velocity(0,0);
            break;
        }
        turnLastError = turnError;
        pros::delay(AUTON_UPDATE_INTERVAL);
        time++;
    }
}

void Autonomous::PID::driveTo(double x,double y,double error=0.02,int timeCap=250, bool reversed = false){
    int time=0;
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
        
        if((fabs(driveError)<error&&abs(driveDerivative)<0.05)||time>timeCap){
            leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
            DriveTrain::move_velocity(0,0);
            break;
        }
        driveLastError = driveError;
        pros::delay(AUTON_UPDATE_INTERVAL);
        time++;
    }
}

void Autonomous::PID::turnToC(double x,double y,double error,int timeCap=200, bool reversed = false){
    Odometry::update();
    double angle = atan2(y-Odometry::get_y(),x-Odometry::get_x());
    double angleDifference = angle - Odometry::theta + PI * int(reversed);
    while(angleDifference>PI) angleDifference-=357.0/180.0 * PI;
    while(angleDifference<-PI) angleDifference+=357.0/180.0 * PI;
    turnTo((angleDifference+Odometry::theta)/PI*180,error,timeCap);
}

void Autonomous::PID::turnThenMoveTo(double x,double y,int turnTimeCap=200, int moveTimeCap=250,bool reversed = false, double angleError = 1.0, double driveError = 0.4){
    Odometry::update();
    turnToC(x,y,angleError,turnTimeCap, reversed);
    driveTo(x,y,driveError,moveTimeCap, reversed);
}


void Autonomous::PID::fastMoveTo(double x,double y,double stopRadius){
    chassis.setPose(0,0,0);
    
}


void Autonomous::Routes::matchWinPointAuton(){
    Odometry::set_theta(135);
    Odometry::set_x(-3);
    Odometry::set_y(-12);
    Wings::toggle2(State::Off); // wings on
    Autonomous::PID::driveTo(-12,-20,0.5,100);// get triball from alliance zone
    Wings::toggle2(State::On); // wings off
    Autonomous::PID::turnThenMoveTo(-30,-25, 0.5,100, true);
    Autonomous::PID::turnThenMoveTo(0,0);
    Autonomous::PID::turnThenMoveTo(0,24);
}

void Autonomous::Routes::sixTriball(){
    Odometry::set_theta(90);
    Odometry::set_theta(24);
    Intake::run(600);
    pros::delay(1000);
    Intake::run(0);
    Autonomous::PID::turnThenMoveTo(-3,-12,100,250,true);
    
    
    Autonomous::PID::turnThenMoveTo(0,24);
    // Autonomous::PID::turnTo(45);
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
    // Autonomous::PID::turnTo(0);
}

void Autonomous::Routes::nearRushMid(){
    Odometry::set_theta(225);
    Odometry::set_x(0);
    Odometry::set_y(-12);
    Autonomous::PID::driveTo(-72,72);
    Intake::run(600);
    // Autonomous::PID::turnTo(180);
    Intake::run(-600);
    Autonomous::PID::driveTo(-50,12);
}


void Autonomous::Routes::testpid(){
    Odometry::set_theta(90);
    rightWheels.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    leftWheels.set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    for (int i = 0; i < 10;i++){
        Autonomous::PID::turnTo(i*90);
    }
    Autonomous::PID::turnThenMoveTo(0,0,200,200,true);
    // return;
    // Autonomous::PID::turnThenMoveTo(0,0,200,250,true);
    // Autonomous::PID::turnThenMoveTo(20,20);
    // Autonomous::PID::turnThenMoveTo(20,0);
    // Autonomous::PID::turnThenMoveTo(0,0);
    // Autonomous::PID::turnTo(90,1.0);
    // Autonomous::PID::turnThenMoveTo(0,0,200,250,1.0,0.4,true);
    // Autonomous::PID::turnTo(0,68,0.02);
    // Autonomous::PID::driveTo(0,68,0.2);
    // Autonomous::PID::turnTo(114,68,0.02);
    // Autonomous::PID::driveTo(114,68,0.2);
    // Autonomous::PID::turnTo(114,0,0.02);
    // Autonomous::PID::driveTo(114,0,0.2);
    // Autonomous::PID::turnTo(0,0,0.02);
    // Autonomous::PID::driveTo(0,0,0.2);
}

void Autonomous::Routes::skillsAuton(){
    Odometry::set_theta(135);
    Odometry::set_x(3);
    Odometry::set_y(-12);
    //need to set robot loc
    Catapult::spinCata();
    pros::delay(500);
    Catapult::stopCata();
    
    // need to change the above later
    // Autonomous::PID::turnThenMoveTo(15,-22,200,250,true);
    Autonomous::PID::driveTo(15,-25,0.5,100);
    Autonomous::PID::turnTo(72);
    Wings::toggle2(State::Off);

    // leftWheels.move_velocity(-100);

    // Autonomous::PID::driveTo(15,-25, 0.5,100);
    // Autonomous::PID::turnThenMoveTo(33,-25,100,100,true);
    // //DriveTrain::move_velocity(600,600);
    // Autonomous::PID::turnThenMoveTo(25,-25,150,175);
    // Autonomous::PID::turnThenMoveTo(20,-20,100,150,true);
    // Autonomous::PID::turnTo(68);
    Catapult::spinCata();
    pros::delay(29000);
    Catapult::stopCata();
    Wings::toggle2(State::On);
    Autonomous::PID::turnThenMoveTo(-3,0,100,100);  
    Autonomous::PID::turnThenMoveTo(0,76);
    Autonomous::PID::turnThenMoveTo(15,91);
    Autonomous::PID::turnThenMoveTo(35,95,150,150,true);
    Autonomous::PID::turnThenMoveTo(30,95,150,150); // reversed
    Autonomous::PID::turnThenMoveTo(42,45,150,150,true);
    Autonomous::PID::turnThenMoveTo(55,45,150,150,true);
    Wings::toggle2(State::Off);
    Autonomous::PID::turnThenMoveTo(60,80,150,150,true); 
    Autonomous::PID::turnToC(65,45,1.0,100,true);
    Wings::toggle2(State::On);
    Autonomous::PID::driveTo(65,45);
    Autonomous::PID::turnToC(75,80,1.0,100,true);
    Wings::toggle2(State::Off);
    Autonomous::PID::driveTo(75,80);
    Autonomous::PID::turnToC(120,76,1.0);
    Wings::toggle2(State::On);
    Autonomous::PID::driveTo(120,76);
    Autonomous::PID::turnThenMoveTo(105,91,200,250,true);\
    Wings::toggle2(State::Off);
    Autonomous::PID::turnThenMoveTo(100,95,200,250,true);
    Autonomous::PID::turnThenMoveTo(105,91);
    Wings::toggle2(State::On);
    return;
    Autonomous::PID::turnThenMoveTo(115,91,true);
    Autonomous::PID::turnThenMoveTo(84,96,true);
    Autonomous::PID::turnThenMoveTo(90,96); // reversed
    Autonomous::PID::turnThenMoveTo(84,96,true);
}
