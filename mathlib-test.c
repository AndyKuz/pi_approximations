#include "mathlib.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define OPTIONS "aebmrvnsh:"

int main(int argc, char *argv[]) {
    int opt = 0;
    bool print_all = false;
    bool print_terms = true;

    for (int i = 0; i < argc; i += 1) {
        if (strcmp(argv[i], "-s") == 0) {
            print_terms = true;
        }
    }

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            print_all = true;

            if (!print_all) {
                break;
            }

        case 'e':
            printf("e() = %16.15lf, ", e());
            printf("M_E = %16.15lf, ", M_E);
            printf("diff = %16.15lf\n", absolute(e() - M_E));

            if (print_terms) {
                printf("e_terms() = %d\n ", e_terms());
            }
            if (!print_all) {
                break;
            }

        case 'r':
            printf("pi_euler() = %16.15lf, ", pi_euler());
            printf("M_PI = %16.15lf, ", M_PI);
            printf("diff = %16.15lf\n", absolute(pi_euler() - M_PI));

            if (print_terms) {
                printf("pi_euler_terms() = %d\n ", pi_euler_terms());
            }

            if (!print_all) {
                break;
            }

        case 'b':
            printf("pi_bbp() = %16.15lf, ", pi_bbp());
            printf("M_PI = %16.15lf, ", M_PI);
            printf("diff = %16.15lf\n", absolute(pi_bbp() - M_PI));

            if (print_terms) {
                printf("pi_bbp_terms() = %d\n ", pi_bbp_terms());
            }

            if (!print_all) {
                break;
            }

        case 'm':
            printf("pi_madhava() = %16.15lf, ", pi_madhava());
            printf("M_PI = %16.15lf, ", M_PI);
            printf("diff = %16.15lf\n", absolute(pi_madhava() - M_PI));

            if (print_terms) {
                printf("pi_madhava_terms() = %d\n ", pi_madhava_terms());
            }

            if (!print_all) {
                break;
            }

        case 'v':
            printf("pi_viete() = %16.15lf, ", pi_viete());
            printf("M_PI = %16.15lf, ", M_PI);
            printf("diff = %16.15lf\n", absolute(pi_viete() - M_PI));

            if (print_terms) {
                printf("pi_viete_factors() = %d\n ", pi_viete_factors());
            }

            if (!print_all) {
                break;
            }

        case 'n':
            for (double i = 0.0; i <= 10.0; i += 0.1) {
                printf("sqrt_newton(%lf) = %16.15lf, ", i, sqrt_newton(i));
                printf("sqrt(%lf) = %16.15lf, ", i, sqrt(i));
                printf("diff = %16.15lf\n", absolute(sqrt_newton(i) - sqrt(i)));

                if (print_terms) {
                    printf("sqrt_newton_iters() = %d\n ", sqrt_newton_iters());
                }
            }
            break;

        case 'h':
            printf(
                "To use mathlib-test use one of the following commands:\n-a: run all tests\n-e: "
                "run e approximation\n-b: run bailey-borwein-plouffe pi approximation\n-m: run "
                "madhava's pi approximation\n-r: run euler's sequence pi approximation\n-v: run "
                "viete's pi approximation\n-n: run newton-raphson square root approximation\n-s: "
                "enable printing of statistics\n-h: to display help message\n");
            break;
        }
    }
    return 0;
}
