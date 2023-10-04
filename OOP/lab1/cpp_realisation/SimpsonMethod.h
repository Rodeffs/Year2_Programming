#ifndef PRACTICE1_SIMPSONMETHOD_H
#define PRACTICE1_SIMPSONMETHOD_H

#include "SolveIntegral.h"


class SimpsonMethod : public SolveIntegral {
public:
    double solve(double (*f)(double), double a, double b) override;
};


#endif //PRACTICE1_SIMPSONMETHOD_H
