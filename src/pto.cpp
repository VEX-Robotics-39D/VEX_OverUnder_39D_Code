#include "main.h"

bool PTO::extended;

void PTO::toggle(State s=State::Toggle){
    switch(s){
        case State::Toggle:
            extended=!extended;
            break;
        case State::On:
            extended=true;
            break;
        case State::Off:
            extended=false;
            break;
    }
    pto.set_value(extended);
}

void PTO::control(){
    if(controller.get_digital(DIGITAL_UP)){
        toggle(State::On);
    }
    else if (controller.get_digital(DIGITAL_DOWN)){
        toggle(State::Off);
    }
}