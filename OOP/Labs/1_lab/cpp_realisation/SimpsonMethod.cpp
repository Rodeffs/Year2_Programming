#include "SimpsonMethod.h"

double SimpsonMethod::solve(double (*f)(double), double a, double b) {
    return (b - a)*(f(a) + 4*f(0.5*(a + b)) + f(b))/6;
}