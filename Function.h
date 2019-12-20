//
// Created by Samuel Prevost on 30/11/2019.
//

#ifndef NEWTONUNIVAR_FUNCTION_H
#define NEWTONUNIVAR_FUNCTION_H
#include "RootList.h"

typedef double (*DoubleToDouble)(double);
//DoubleToDouble nth_derivative(Function* f, int n){ ... }
// same as
// double (*nth_derivative(Function* f, int n))(double){ ... }

typedef struct Function {
    double (*functionPtr)(double);
    double x_min;
    double x_max;
    struct Function* derivative;
} Function;

DoubleToDouble nth_derivative(Function* f, int n);

Function* copy_array_to_heap(Function* function_array, int length);
Function* copy_to_heap(Function* function);

double compute_poly(RootList* root_list, double x);

#endif //NEWTONUNIVAR_FUNCTION_H
