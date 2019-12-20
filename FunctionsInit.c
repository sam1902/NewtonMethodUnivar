//
// Created by Samuel Prevost on 30/11/2019.
//

#include <stdlib.h>
#include <math.h>
#include "FunctionsInit.h"

/***
 * Creates the basic functions we want to work on as Function structs
 * and does so on the heap so that it's still available after calling the function.
 * @return an array of FUNCOUNT number of Function structures allocated on the heap.
 */
Function* getAllFunctions(){
    Function funcs_d2[FUNCOUNT] = {
            {.functionPtr = &f0_d2, .derivative = NULL, .x_min = -4.47, .x_max = 2.46},
            {.functionPtr = &f1_d2, .derivative = NULL, .x_min = -5, .x_max = 5},
            {.functionPtr = &f2_d2, .derivative = NULL, .x_min = 0.1, .x_max = 5},
    };

    Function funcs_d[FUNCOUNT] = {
            {.functionPtr = &f0_d, .derivative = funcs_d2 + 0, .x_min = -4.47, .x_max = 2.46},
            {.functionPtr = &f1_d, .derivative = funcs_d2 + 1, .x_min = -5, .x_max = 5},
            {.functionPtr = &f2_d, .derivative = funcs_d2 + 2, .x_min = 0.1, .x_max = 5},
    };

    Function funcs[FUNCOUNT] = {
            {.functionPtr = &f0, .derivative = funcs_d + 0, .x_min = -4.47, .x_max = 2.46},
            {.functionPtr = &f1, .derivative = funcs_d + 1, .x_min = -5, .x_max = 5},
            {.functionPtr = &f2, .derivative = funcs_d + 2, .x_min = 0.1, .x_max = 5},
    };

    return copy_array_to_heap(funcs, FUNCOUNT);
}

double f0(double x){
    return -2*exp(pow(-(x+1),2));
}

double f1(double x){
    return pow(x,4)/4-2*pow(x,2)+x;
}

double f2(double x){
    return pow(x,2)/2 - 3*x*(log(x)-1);
}

double f0_d(double x){
    return 4 * exp(-pow(1 + x, 2)) * (1 + x);
}

double f1_d(double x){
    return 1 - 4*x + pow(x,3);
}

double f2_d(double x){
    return x - 3*log(x);
}

double f0_d2(double x){
    return -4*exp(-pow(1+x,2))*(2*pow(x,2)+4*x+1);
}

double f1_d2(double x){
    return 3*pow(x,2)-4;
}

double f2_d2(double x){
    return (x-3)/x;
}