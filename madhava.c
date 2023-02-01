#include "mathlib.h"

#include <stdio.h>

static int num_madhava_terms = 0;

double pi_madhava(void) {
    num_madhava_terms = 0;
    double k_val = 0.0;
    double madhava_pi_approximation = 0.0;
    double current_term = 2.0;
    double powered_term = 1.0;

    while (absolute(current_term) >= EPSILON) {
        if (k_val != 0.0) {
            powered_term *= -3.0;
        }
        current_term = 1 / (((2.0 * k_val) + 1) * powered_term);
        madhava_pi_approximation += current_term;

        k_val++;
        num_madhava_terms++;
    }

    return (sqrt_newton(12.0) * madhava_pi_approximation);
}

int pi_madhava_terms(void) {
    return num_madhava_terms;
}
