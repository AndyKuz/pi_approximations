#include "mathlib.h"

#include <stdio.h>

static int num_newton_iterations = 0;

double sqrt_newton(double x) {
    double z = 0.0;
    double y = 1.0;
    num_newton_iterations = 0;

    while (absolute((y - z)) > EPSILON) {
        z = y;
        y = 0.5 * (z + x / z);
        num_newton_iterations++;
    }
    return y;
}

int sqrt_newton_iters(void) {
    return num_newton_iterations;
}
