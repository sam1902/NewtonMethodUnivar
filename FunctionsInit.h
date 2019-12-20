//
// Created by Samuel Prevost on 30/11/2019.
//

#ifndef NEWTONUNIVAR_FUNCTIONSINIT_H
#define NEWTONUNIVAR_FUNCTIONSINIT_H

#include "Function.h"

#define FUNCOUNT 3

Function* getAllFunctions();

double f0(double x);
double f1(double x);
double f2(double x);

double f0_d(double x);
double f1_d(double x);
double f2_d(double x);

double f0_d2(double x);
double f1_d2(double x);
double f2_d2(double x);

#endif //NEWTONUNIVAR_FUNCTIONSINIT_H
