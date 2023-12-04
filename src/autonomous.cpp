#include "main.h"

ASSET(path_txt);

void Autonomous::Routes::testpid(){
    chassis.setPose(-36,58,90);
    chassis.follow(path_txt,60000,15);
}

