#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-flp30-c"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#include "FunctionsInit.h"
#include "RootList.h"
#include "Function.h"

#define X_MIN -5
#define X_MAX 5
#define OUTPUT_FILENAME "funcs_roots.csv"

#define APPROX_EPS 0.0001
#define COMPARISON_EPS 0.01
#define STEP_EPS 0.01

int main() {
    Function* funcs = getAllFunctions();

    FILE* output_file = fopen(OUTPUT_FILENAME, "w");
    if (output_file == NULL){
        fprintf(stderr, "Couldn't open %s in write mode.", OUTPUT_FILENAME);
        exit(1);
    }

    fprintf(output_file, "f_i,x0,root,it_count\n");

    /*
     * Finds the zeroes of the derivative of each functions
     * check if one isn't very close to one we already found
     * and if it isn't, logs it to a CSV file along with the
     * starting value of the algorithm.
     */
    for (int i = 0; i < FUNCOUNT; i++) {
        DoubleToDouble df = nth_derivative(&funcs[i], 1);
        DoubleToDouble d2f = nth_derivative(&funcs[i], 2);
        RootList* root_list = NULL;
        double x_min = funcs[i].derivative->x_min;
        double x_max = funcs[i].derivative->x_max;
        printf("x in [%.5f, %.5f]\n", x_min, x_max);

        for(double x0 = x_min; x0 < x_max; x0 += STEP_EPS){
            double new_root = x0;
            int it_count = 0;

            while (fabs(df(new_root)) > APPROX_EPS){
                ++it_count;
                // TODO: use Maehly's procedure
                new_root -= df(new_root) / d2f(new_root) * 0.01;
            }

            if (new_root > x_min && new_root < x_max) {
                if (root_list == NULL || !is_in(*root_list, new_root, COMPARISON_EPS)) {
                    root_list = add(root_list, new_root, it_count);
                    fprintf(output_file, "%d,%.5f,%.5f,%d\n", i, x0, root_list->val, root_list->it_count);
                }
            }
        }
        printf("Number of roots found for f_%d: %d\n", i, len(root_list));
        printf("f_%d done !\n", i);
        printf("#####################################\n");
    }
    fclose(output_file);
    return 0;
}