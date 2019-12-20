//
// Created by Samuel Prevost on 30/11/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "Function.h"

/***
 * Returns the nth derivative of the given function
 * @param f
 * @param n
 * @return
 */
DoubleToDouble nth_derivative(Function* f, int n){
    if (n != 0 && f->derivative != NULL){
        return nth_derivative(f->derivative, n-1);
    } else {
        return f->functionPtr;
    }
}

/***
 * Copies an array of Function to the heap.
 * @param function_array
 * @param length
 * @return a pointer to the copied array of structs
 */
Function* copy_array_to_heap(Function* function_array, int length){
    Function* function_array_on_heap = malloc(sizeof(Function)*length);
    for (int i = 0; i < length; ++i) {
        function_array_on_heap[i] = *copy_to_heap(function_array + i);
    }
    return function_array_on_heap;
}

/***
 * Copies a Function to the heap, as well as its sub-structures, recursively.
 * @param function
 * @return a pointer to the copied struct's head
 */
Function* copy_to_heap(Function* function){
    if (function == NULL){
        return NULL;
    }
    Function* heap_fun = malloc(sizeof(Function));
    heap_fun->functionPtr = function->functionPtr;
    heap_fun->x_min = function->x_min;
    heap_fun->x_max = function->x_max;
    heap_fun->derivative = copy_to_heap(function->derivative);
    return heap_fun;
}

double _tail_rec_compute_poly(RootList* root_list, double x, double acc) {
    if (root_list == NULL){
        return acc;
    }
    double new_acc = acc * (x - root_list->val);
    return _tail_rec_compute_poly(root_list->next, x, new_acc);
}

/***
 * Computes the value of the polynomial
 * y = (x - x_0))(x - x_1)(x - x_2) ... (x - x_n-1)(x - x_n)
 * evaluated in `x`, where x_0, x_1, ..., x_n are the roots in `root_list`
 * @param root_list
 * @param x
 * @return
 */
double compute_poly(RootList* root_list, double x) {
    return _tail_rec_compute_poly(root_list, x, 1);
}