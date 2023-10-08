#include "main.h"

bool PTO::extended=false;

void PTO::control(){
    if(controller.get_digital(DIGITAL_UP)){
        if(extended){
            pto.set_value(false);
            extended=false;
        }
    }
    else if (controller.get_digital(DIGITAL_DOWN)){
        if(!extended){
            pto.set_value(true);
            extended=true;
        }
    }
}