#include "main.h"

double Utilities::bound_by(double l,double r,double value){
    value=fmax(l,value);
    value=fmin(r,value);
    return value;
}

double Utilities::drive_control_map(double input){
    if(abs(input)<16){
        return 0;
    }
    if(input>0){
        return (input-16)/111.0;
    }
    else{
        return (input+16)/111.0;
    }
} 
