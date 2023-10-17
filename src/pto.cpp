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