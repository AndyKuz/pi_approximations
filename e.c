#include "mathlib.h"

#include <stdio.h>

static int num_e_iterations = 1;

double e(void) {
    num_e_iterations = 1;
    double e_return_val = 0.0;
    double k_val = 1.0;

    while (EPSILON < (1.0 / k_val)) {
        e_return_val += (1.0 / k_val);
        k_val = num_e_iterations * k_val;
        num_e_iterations++;
    }

    return e_return_val;
}

int e_terms(void) {
    return (num_e_iterations + 1);
}
