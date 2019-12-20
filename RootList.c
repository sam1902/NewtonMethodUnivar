//
// Created by Samuel Prevost on 30/11/2019.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "RootList.h"

int len(RootList* root_list){
    int l = 0;
    if (root_list == NULL) {
        return l;
    }
    do {
        l += 1;
    } while ((root_list = root_list->next) != NULL);
    return l;
}

RootList* add(RootList* root_list, double val, int it_count){
    RootList* new_head = malloc(sizeof(RootList));
    new_head->next = root_list;
    new_head->it_count = it_count;
    new_head->val = val;
    return new_head;
}

/***
 * Checks if a values `val` is in the `root_list` val, with absolute tolerance `eps`
 * @param root_list
 * @param val
 * @param eps
 * @return true if it's close enough to one of the values, false otherwise
 */
bool is_in(RootList root_list, double val, double eps){
    if (fabs(root_list.val - val) <= eps){
        return true;
    } else if (root_list.next != NULL) {
        return is_in(*root_list.next, val, eps);
    } else {
        return false;
    }
}
