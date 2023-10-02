#include "SolveIntegral.h"

double SolveIntegral::solve(double (*f)(double), double a, double b) {}

SolveIntegral::SolveIntegral() = default;

SolveIntegral::~SolveIntegral() = default;

int SolveIntegral::getQuantity() {
    return this->pointsQuantity;
}

void SolveIntegral::setQuantity(int x) {
    if (x <= 0)
        throw std::invalid_argument("The number of points must be a positive number");
    else
        this->pointsQuantity = x;
}