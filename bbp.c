#include "mathlib.h"

#include <stdio.h>

static int pi_bbp_iterations = 0;

double pi_bbp(void) {
    pi_bbp_iterations = 0;
    double k_val = 0.0;
    double current_iteration = 2.0;
    double return_value = 0.0;
    double powered_val = 1;
    double first_val = 0.0;

    while (current_iteration > EPSILON) {
        if (k_val != 0.0) {
            powered_val *= 16.0;
        }
        first_val = 1 / powered_val;
        current_iteration = first_val
                            * ((4 / ((8 * k_val) + 1)) - (2 / ((8 * k_val) + 4))
                                - (1 / ((8 * k_val) + 5)) - (1 / ((8 * k_val) + 6)));
        return_value += current_iteration;
        pi_bbp_iterations++;
        k_val++;
    }

    return return_value;
}

int pi_bbp_terms(void) {
    return pi_bbp_iterations;
}
