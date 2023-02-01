#include "mathlib.h"

#include <stdio.h>

static int num_euler_iterations = 0;

double pi_euler(void) {
    double k_val = 1.0;
    double euler_pi_approximation = 0.0;
    num_euler_iterations = 0;

    while ((1 / (k_val * k_val)) > EPSILON) {
        euler_pi_approximation += 1 / (k_val * k_val);
        num_euler_iterations++;
        k_val++;
    }
    euler_pi_approximation *= 6;
    euler_pi_approximation = sqrt_newton(euler_pi_approximation);
    return euler_pi_approximation;
}

int pi_euler_terms(void) {
    return num_euler_iterations;
}
