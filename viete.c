#include "mathlib.h"

#include <stdio.h>

static int num_viete_iterations = 1.0;

double pi_viete(void) {
    double numerator = 0.0;
    double viete_pi_approximation = 1.0;
    num_viete_iterations = 1.0;

    do {
        numerator = sqrt_newton((2.0 + numerator));
        viete_pi_approximation *= (numerator / 2.0);

        num_viete_iterations++;

    } while (viete_pi_approximation - (viete_pi_approximation * (numerator / 2.0)) > EPSILON);

    viete_pi_approximation = (1.0 / viete_pi_approximation) * 2.0;
    return viete_pi_approximation;
}

int pi_viete_factors(void) {
    return num_viete_iterations;
}
