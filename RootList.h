//
// Created by Samuel Prevost on 30/11/2019.
//

#ifndef NEWTONUNIVAR_ROOTLIST_H
#define NEWTONUNIVAR_ROOTLIST_H
#include <stdbool.h>

typedef struct RootList {
    double val;
    int it_count;
    struct RootList* next;
} RootList;

int len(RootList* root_list);
RootList* add(RootList* root_list, double val, int it_count);
bool is_in(RootList root_list, double val, double eps);

#endif //NEWTONUNIVAR_ROOTLIST_H
