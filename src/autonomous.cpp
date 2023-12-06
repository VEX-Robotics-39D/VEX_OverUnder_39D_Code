#include "main.h"

ASSET(path_txt);

void Autonomous::Routes::testpid(){
    chassis.setPose(-36,58,90);
    chassis.follow(path_txt,60000,15);
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

void Autonomous::Routes::skillauton(){
    chassis.setPose(53,-46,-90);
    chassis.follow(skill1_txt,10000,15);
    chassis.follow(skill2_txt,4000,15);
    chassis.follow(skill3_txt,6000,15);
    chassis.follow(skill4_txt,6000,15);
    chassis.follow(skill5_txt,6000,15);
}

