#include "main.h"

void Catapult::spinCata(){
    catapult.move_velocity(600);
}
void Catapult::stopCata(){
    catapult.move_velocity(0);
}