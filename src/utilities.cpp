#include "main.h"

double Utilities::bound_by(double l,double r,double value){
    value=fmax(l,value);
    value=fmin(r,value);
    return value;
}