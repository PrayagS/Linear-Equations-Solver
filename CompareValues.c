#include <stdio.h>
#include <math.h>

int compareDoubles(double x, double y){
    if(fabs(x-y) < 1e-8){
        return 1;
    }
    else{
        return 0;
    }
}